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

struct Point {
  int s, t;
  int num, lowest, parent;
  Point (int s, int t) : s(s), t(t) {
    num = -1;
    lowest = -1;
    parent = -1;
  }
};

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<Point> vp;

void print(vp VP, int *chl) {
  rep(i, VP.size()) {
    cout << i << ": NUM " << VP[i].num << ", LOW " << VP[i].lowest << ", PAR " << VP[i].parent << ", CHL_NUM " << chl[i] << endl;
  }
}

int main() {
  int V, E;
  cin >> V >> E;
  vvi e;
  int t, s;
  vp vps;
  rep(i, V) e.push_back(vi());
  rep(i, E) {
    cin >> s >> t;
    e[s].push_back(i);
    e[t].push_back(i);
    vps.push_back(Point(s, t));
  }
  set<int> S;
  stack<pair<int, int> > st;
  stack<int> st2;
  rep(i, V) {
    if (S.find(i) != S.end()) continue;
    S.insert(i);
    st2.push(i);
    set<int> temp_set;
    temp_set.insert(i);
    rep(j, e[i].size()) st.push(make_pair(i, vps[e[i][j]].t));
    int cur = 0;
    vps[i].num = cur++;
    while (!st.empty()) {
      pair<int, int> st_top = st.top();
      st.pop();
      if (st_top.first == st2.top()) {
        continue;
      } else if (S.find(st_top.second) == S.end()) {
        vps[st_top.second].num = cur++;
        vps[st_top.second].lowest = vps[st_top.second].num;
        vps[st_top.second].parent = st_top.first;
        S.insert(st_top.second);
        st2.push(st_top.second);
        rep(j, e[st_top.second].size()) st.push(make_pair(st_top.second, vps[e[st_top.second][j]].t));
      } else {
        vps[st_top.first].lowest = min(vps[st_top.first].lowest, vps[st_top.second].num);
      }
    }
  }
  int chl_num[V];
  fill(chl_num, chl_num+V, 0);
  while (!st2.empty()) {
    int cur_chl = st2.top();
    st2.pop();
    if (vps[cur_chl].parent == -1) continue;
    if (vps[vps[cur_chl].parent].parent == -1) chl_num[vps[cur_chl].parent]++;
    vps[vps[cur_chl].parent].lowest = min(vps[vps[cur_chl].parent].lowest, vps[cur_chl].lowest);
  }
  set<int> ans;
  rep(i, V) if (chl_num[i] > 1) ans.insert(i);
  rep(i, V) {
    if (vps[i].parent == -1) continue;
    if (vps[vps[i].parent].num <= vps[i].lowest && vps[vps[i].parent].parent != -1) ans.insert(vps[i].parent);
  }
  // print(vps, chl_num);
  set<int>::iterator st_it = ans.begin();
  rep(i, S.size()) cout << *st_it++ << endl;



  return 0;
}
