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

int dfs(Graph &G, int start, int end, int cost, vector<bool> &used) {
  if (start == end) return cost;
  rep(i, G[start].size()) {
    if (G[start][i].cost == 0 || used[G[start][i].to]) continue;
    used[G[start][i].to] = true;
    int new_cost = min(cost, G[start][i].cost);
    new_cost = dfs(G, G[start][i].to, end, new_cost, used);
    if (new_cost == 0) continue;
    G[start][i].cost -= new_cost;
    G[G[start][i].to][G[start][i].rev].cost += new_cost;
    return new_cost;
  }
  return 0;
}

int main() {
  int V, E;
  cin >> V >> E;
  Graph G;
  rep(i, V) G.push_back(Edges());
  int u, v, c;
  rep(i, E) {
    cin >> u >> v >> c;
    G[u].push_back(Edge(v, c, G[v].size()));
    G[v].push_back(Edge(u, 0, G[u].size()-1));
  }
  int sum = 0;
  vector<bool> used(V);
  while (true) {
    fill(used.begin(), used.end(), false);
    int d = dfs(G, 0, V-1, MOD, used);
    sum += d;
    if (d == 0) break;
  }
  cout << sum << endl;
  return 0;
}
