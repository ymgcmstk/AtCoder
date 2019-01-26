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
  Edge(int to, int cost) : to(to), cost(cost) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef pair<int, int> PII;

int main() {
  int N;
  cin >> N;
  // source code
  Graph G;
  rep(i, N) G.push_back(Edges());
  int s, t, w;
  rep(i, N) {
    cin >> s >> t >> w;
    G[s].push_back(Edge(t, w));
    G[t].push_back(Edge(s, w));
  }
  priority_queue<PII, vector<PII>, greater<PII> > pq;
  rep(i, G[0].size()) pq.push(make_pair(G[0][i].cost, G[0][i].to));
  set<int> S;
  S.insert(0);
  int max_ind = 0;
  int cur_max = 0;
  while (S.size() < N) {
    PII cur_pair = pq.top();
    pq.pop();
    if (S.find(cur_pair.second) != S.end()) continue;
    S.insert(cur_pair.second);
    if (cur_pair.first > cur_max) {
      cur_max = cur_pair.first;
      max_ind = cur_pair.second;
    }
    rep(i, G[cur_pair.second].size()) {
      if (S.find(G[cur_pair.second][i].to) != S.end()) continue;
      pq.push(make_pair(G[cur_pair.second][i].cost+cur_pair.first, G[cur_pair.second][i].to));
    }
  }
  while (!pq.empty()) pq.pop();
  S.clear();
  rep(i, G[max_ind].size()) pq.push(make_pair(G[max_ind][i].cost, G[max_ind][i].to));
  S.insert(max_ind);
  cur_max = 0;
  while (S.size() < N) {
    PII cur_pair = pq.top();
    pq.pop();
    if (S.find(cur_pair.second) != S.end()) continue;
    S.insert(cur_pair.second);
    if (cur_pair.first > cur_max) {
      cur_max = cur_pair.first;
      max_ind = cur_pair.second;
    }
    rep(i, G[cur_pair.second].size()) {
      if (S.find(G[cur_pair.second][i].to) != S.end()) continue;
      pq.push(make_pair(G[cur_pair.second][i].cost+cur_pair.first, G[cur_pair.second][i].to));
    }
  }
  cout << cur_max << endl;
  return 0;
}
