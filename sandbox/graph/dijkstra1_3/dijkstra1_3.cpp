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

int main() {
  int V, E, r;
  // cin >> N;
  cin >> V >> E >> r;
  Graph G;
  rep(i, V) G.push_back(vector<Edge>());
  int s, t, d_;
  rep(i, E) {
    cin >> s >> t >> d_;
    G[s].push_back(Edge(t, d_));
    // G[t].push_back(Edge(s, d_));
  }
  // vector<int> d = dijkstra(G, true);
  vector<int> d = dijkstra(G, r, -1, false);
  rep(i, V) cout << d[i] << endl;
    // cout << i << ' ' << d[i] << endl;
  return 0;
}
