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

struct Edge {
  int to, cost;
  Edge (int to, int cost) : to(to), cost(cost) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

vector<int> dijkstra(Graph G, int start=0, int end=-1, bool is_directed=true) {
  if (!is_directed) {
    int edge_num[G.size()];
    rep(i, G.size()) edge_num[i] = G[i].size();
    rep(i, G.size()) rep(j, edge_num[i]) G[G[i][j].to].push_back(Edge(i, G[i][j].cost));
  }
  vector<int> d(G.size());
  fill(d.begin(), d.end(), MOD);
  d[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  rep(i, G[start].size()) pq.push(make_pair(G[start][i].cost, G[start][i].to));
  set<int> S;
  S.insert(start);
  while (S.size() < G.size() && pq.size() > 0) {
    pair<int, int> temp_p = pq.top();
    pq.pop();
    if (S.find(temp_p.second) != S.end()) continue;
    S.insert(temp_p.second);
    d[temp_p.second] = temp_p.first;
    rep(i, G[temp_p.second].size()) {
      if (S.find(G[temp_p.second][i].to) != S.end()) continue;
      pq.push(make_pair(G[temp_p.second][i].cost + d[temp_p.second], G[temp_p.second][i].to));
    }
    if (S.find(end) != S.end()) break;
  }
  return d;
}


bool check_cur_state(vector<int> &x, vector<int> &y, int N, vector<bool> &cur_state, int new_node) {
  if (new_node < 0) return false;
  Graph G(N);
  // rep(i, N) G[i] = Edges();
  rep(i, cur_state.size()) {
    if (i == new_node) continue;
    if (!cur_state[i]) continue;
    G[x[i]].push_back(Edge(y[i], 1));
  }
  vector<int> cur_vi = dijkstra(G, x[new_node], y[new_node], false);
  if (cur_vi[y[new_node]] % 2 == 0) return true;
  return false;
}

string get_cur_state(vector<bool> &cur_state) {
  string ans = "";
  rep(i, cur_state.size()){
    if (cur_state[i]) ans += "1";
    else ans += "0";
  }
  return ans;
}

int cur_dfs(vector<int> &x, vector<int> &y, int N, vector<bool> &cur_state, int new_node, set<string> &elist) {
  int ans = 0;
  int cur_val;
  if (check_cur_state(x, y, N, cur_state, new_node)) {
    return 0;
  }
  rep(i, cur_state.size()) {
    if (cur_state[i]) continue;
    cur_state[i] = true;
    ans += cur_dfs(x, y, N, cur_state, i, elist);
    cur_state[i] = false;
  }
  if (ans == 0) {
    // show_vec(cur_state);
    string cur_state_str = get_cur_state(cur_state);
    if (elist.find(cur_state_str) != elist.end()) return 1;
    elist.insert(cur_state_str);
    return 1;
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> x(M), y(M);
  rep(i, M) cin >> x[i] >> y[i];
  rep(i, M) {
    x[i]--;
    y[i]--;
  }
  vector<bool> cur_state(M);
  fill(cur_state.begin(), cur_state.end(), false);
  set<string> elist;
  int ans = cur_dfs(x, y, N, cur_state, -1, elist);
  cout << elist.size() << endl;
  return 0;
}
