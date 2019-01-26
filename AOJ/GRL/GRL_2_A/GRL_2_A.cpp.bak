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
  Edge (int to, int cost): to(to), cost(cost) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int main() {
  int V, E;
  cin >> V >> E;
  int s, t, w;
  Graph G;
  rep(i, V) G.push_back(Edges());
  rep(i, E) {
    cin >> s >> t >> w;
    G[s].push_back(Edge(t, w));
    G[t].push_back(Edge(s, w));
  }
  set<int> S;
  S.insert(0);
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  rep(i, G[0].size()) pq.push(make_pair(G[0][i].cost, G[0][i].to));
  pair<int, int> cur_p;
  int sum = 0;
  while (S.size() < V) {
    cur_p = pq.top();
    pq.pop();
    if (S.find(cur_p.second) != S.end()) continue;
    // cout << cur_p.second << ';'  << cur_p.first << ';' << endl;
    S.insert(cur_p.second);
    sum += cur_p.first;
    rep(i, G[cur_p.second].size()) {
      pq.push(make_pair(G[cur_p.second][i].cost, G[cur_p.second][i].to));
    }
  }
  cout << sum << endl;
  return 0;
}
