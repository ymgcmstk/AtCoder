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

bool debug_mode = true;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int N, M;
  cin >> N >> M;
  vvi AL(N);
  int flg[N];
  fill(flg, flg+N, -1);
  int s, t;
  rep(i, M) {
    cin >> s >> t;
    AL[s].push_back(t);
    AL[t].push_back(s);
  }
  int cur_v;
  rep(i, N) {
    if (flg[i] > -1) continue;
    stack<int> Vs;
    rep(j, AL[i].size()) Vs.push(AL[i][j]);
    while (Vs.size() > 0) {
      cur_v = Vs.top();
      Vs.pop();
      if (flg[cur_v] > -1) continue;
      flg[cur_v] = i;
      rep(k, AL[cur_v].size()) {
        if (flg[AL[cur_v][k]] > -1) continue;
        Vs.push(AL[cur_v][k]);
      }
    }
  }
  int Q;
  cin >> Q;
  rep(i, Q) {
    cin >> s >> t;
    if (flg[s] == flg[t]) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
