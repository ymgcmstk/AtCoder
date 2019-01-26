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

struct Edge {
  int to, cost, rev;
  Edge (int to, int cost) : to(to), cost(cost) {}
  Edge (int to, int cost, int rev) : to(to), cost(cost), rev(rev) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int dfs(Graph &G, int start, int end, int cur_flow, vector<bool> &used) {
  if (start == end) {
    return cur_flow;
  }
  used[start] = true;
  int d = 0;
  rep(i, G[start].size()) {
    if (used[G[start][i].to] || G[start][i].cost == 0) continue;
    int next_flow = min(G[start][i].cost, cur_flow);
    d = dfs(G, G[start][i].to, end, next_flow, used);
    if (d > 0) {
      G[start][i].cost -= d;
      G[G[start][i].to][G[start][i].rev].cost += d;
      break;
    }
  }
  return d;
}

Graph max_flow(Graph _G, int start=0, int end=-1) {
  if (end == -1) end = _G.size() - 1;
  Graph G;
  rep(i, _G.size()) G.push_back(Edges());
  rep(i, _G.size()) {
    rep(j, _G[i].size()) {
      G[i].push_back(Edge(_G[i][j].to, _G[i][j].cost, G[_G[i][j].to].size()));
      G[_G[i][j].to].push_back(Edge(i, 0, G[i].size()-1));
    }
  }
  int d = 1;
  vector<bool> used(G.size());
  while (d > 0) {
    fill(used.begin(), used.end(), false);
    d = dfs(G, start, end, MOD, used);
  }
  return G;
}

int main() {
  int V, E;
  cin >> V >> E;
  Graph G;
  rep(i, V) G.push_back(Edges());
  int u, v, c;
  rep(i, E) {
    cin >> u >> v >> c;
    G[u].push_back(Edge(v, c));
  }
  Graph ans_g = max_flow(G, 0, G.size()-1);
  int cur_sum = 0;
  rep(i, G[0].size()) {
    cur_sum += G[0][i].cost - ans_g[0][i].cost;
  }
  cout << cur_sum << endl;
  return 0;
}
