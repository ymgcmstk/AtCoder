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

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

typedef vector<int> vpi;
typedef vector<vpi> vvpi;

typedef stack<int> stack_i;
typedef queue<int> queue_i;

void print(int num, int *prenum, int *lowest, int *parent, int *chl) {
  rep(i, num) {
    cout << i << ": NUM " << prenum[i] << ", LOW " << lowest[i] << ", PAR " << parent[i] << ", CHL_NUM " << chl[i] << endl;
  }
}

//  print(V, prenum, lowest, parent, chlnum);

int main() {
  int V, E;
  cin >> V >> E;
  int prenum[V], parent[V], lowest[V], chlnum[V];
  fill(prenum, prenum+V, -1);
  fill(parent, parent+V, -1);
  fill(lowest, lowest+V, MOD);
  fill(chlnum, chlnum+V, 0);

  vvpi p2ps;
  rep(i, V) p2ps.push_back(vpi());
  int s, t;
  rep(i, E) {
    cin >> s >> t;
    p2ps[s].push_back(t);
    p2ps[t].push_back(s);
  }
  set<int> S;
  stack<int> si_for_reversing;
  rep(i, V) {
    if (S.find(i) != S.end()) continue;
    int cur_ind = 0;
    prenum[i] = cur_ind;
    lowest[i] = cur_ind;
    si_for_reversing.push(i);
    cur_ind++;
    set<int> points;
    S.insert(i);
    points.insert(i);
    stack<pii> cur_spii;
    rep(j, p2ps[i].size()) cur_spii.push(make_pair(i, p2ps[i][j]));
    while (!cur_spii.empty()) {
      pii cur_pii = cur_spii.top();
      cur_spii.pop();
      if (points.find(cur_pii.second) == points.end()) {
        prenum[cur_pii.second] = cur_ind;
        lowest[cur_pii.second] = cur_ind;
        parent[cur_pii.second]  = cur_pii.first;
        si_for_reversing.push(cur_pii.second);
        if (parent[cur_pii.first] == -1) chlnum[cur_pii.first]++;
        cur_ind++;
        rep(j, p2ps[cur_pii.second].size()) {
          if (p2ps[cur_pii.second][j] == cur_pii.first) continue;
          cur_spii.push(make_pair(cur_pii.second, p2ps[cur_pii.second][j]));
        }
        points.insert(cur_pii.second);
        S.insert(cur_pii.second);
      } else {
        lowest[cur_pii.first] = min(lowest[cur_pii.first], lowest[cur_pii.second]);
      }
    }
  }
  while (!si_for_reversing.empty()) {
    int next_ind = si_for_reversing.top();
    si_for_reversing.pop();
    int cur_par = parent[next_ind];
    if (cur_par == -1) continue;
    lowest[cur_par] = min(lowest[next_ind], lowest[cur_par]);
  }
  set<int> ans;
  rep(i, V) {
    if (prenum[i] == 0) {
      if (chlnum[i] > 1) ans.insert(i);
      continue;
    }
    if (prenum[parent[i]] > 0 && prenum[parent[i]] <= lowest[i]) ans.insert(parent[i]);
  }
  set<int>::iterator ans_iter = ans.begin();
  rep(i, ans.size()) cout << *ans_iter++ << endl;
  // print(V, prenum, lowest, parent, chlnum);
  return 0;
}
