// This template is based on http://ctylim.hatenablog.com/entry/2015/08/30/191553, provided by ctylim.
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <utility>

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define mrepd(i,a,b) for (int i=(b-1);i>=(a);i--)
#define rep(i,n) repd(i,0,n)
#define mrep(i,n) mrepd(i,0,n)
#define LL long long
#define MOD 1000000007
using namespace std;

template <typename T> void input_array(T * p){
  int a = sizeof(p) / sizeof(p[0]);
  rep(i, a){
    cin >> p[i];
  }
}

void input_vector(vector<int> * p, int a){
  rep(i, a){
    int input;
    cin >> input;
    p -> push_back(input);
  }
}

template <typename T>
void output(T a, int precision) {
  if (precision > 0) {
    cout << setprecision(precision)  << a << "\n";
  } else {
    cout << a << "\n";
  }
}

template <typename T>
void show_array(T arr[]) {
  rep(i, sizeof(*arr)/sizeof(arr[0])) cout << arr[i] << ' ';
  cout << endl;
}


template <typename T>
void show_vec(vector<T> vec) {
  rep(i, vec.size()) cout << vec[i] << ' ';
  cout << endl;
}

bool debug_mode = false;

int bit_count(int i) {
  int ans = 0;
  int cur_targ = 1;
  while (cur_targ <= i) {
    if ((i & cur_targ) > 0) ans++;
    cur_targ <<= 1;
  }
  return ans;
}

int cuttable(int cut_targ, int N, vector<int> a, vector<int> b, vector<int> p, vector<set<int> > &VSs) {
  int ans = 0;
  vector<int> new_a, new_b;
  set<int> S, cuttable_S;
  S.insert(0);
  int cur_bit = 1;
  while (cur_bit <= cut_targ) {
    if ((cut_targ & cur_bit) > 0) {
      for (set<int>::iterator s = VSs[cut_targ & (!cur_bit)].begin(); VSs[cut_targ & (!cur_bit)].end() != s; s++) cuttable_S.insert(*s);
    }
    cur_bit <<= 1;
  }

  rep(i, a.size()) {
    if (((1 << i) & cut_targ) > 0) continue;
    // if (cuttable_S.find(a[i]) != cuttable_S.end() || cuttable_S.find(b[i]) != cuttable_S.end()) continue;
    if (cuttable_S.find(a[i]) != cuttable_S.end()) continue;
    new_a.push_back(a[i]);
    new_b.push_back(b[i]);
  }

  int cur_size = S.size()-1;
  bool ai_in_S, bi_in_S;
  while (cur_size < S.size()) {
    if (debug_mode) cout << "counting cuttable nodes ... " << endl;
    cur_size = S.size();
    mrep(i, new_a.size()) {
      ai_in_S = (S.find(new_a[i]) != S.end());
      bi_in_S = (S.find(new_b[i]) != S.end());
      if (ai_in_S & bi_in_S) {
        new_a.erase(new_a.begin() + i);
        new_b.erase(new_b.begin() + i);
      } else if (ai_in_S) S.insert(new_b[i]);
      else if (bi_in_S) S.insert(new_a[i]);
    }
  }
  rep(i, p.size()) if (S.find(p[i]) == S.end()) ans++;
  rep(i, N) if (S.find(i) == S.end()) cuttable_S.insert(i);
  VSs[cut_targ] = cuttable_S;
  return ans;
}

int main() {
  int N, G, E;
  cin >> N >> G >> E;
  vector<int> p(G);
  rep(i, G) cin >> p[i];
  vector<int> a(E), b(E);
  rep(i, E) cin >> a[i] >> b[i];
  if (E > 12) return 0;
  // bool flg[1 << E];
  vector<set<int> > VSs((1 << E));
  if (VSs.size() != (1 << E)) cout << "something wrong" << endl;
  int cur_min = E;
  VSs[0] = set<int>(); // cuttable nodes
  repd(i, 1, 1 << E) {
    int this_cuttable = cuttable(i, N, a, b, p, VSs);
    cur_min = min((G - this_cuttable) + bit_count(i), cur_min);
  }
  cout << cur_min << endl;
  return 0;
}
