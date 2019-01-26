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
  Edge(int to, int cost): to(to), cost(cost) {};
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int main() {
  int N;
  cin >> N;
  // source code
  int temp;
  Graph G;
  rep(i, N) G.push_back(Edges());
  rep(i, N) rep(j, N) {
    cin >> temp;
    if (temp < 0) continue;
    G[i].push_back(Edge(j, temp));
  }
  set<int> S;
  S.insert(0);
  int fans = 0;
  Edges cur_edges;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  rep(i, G[0].size()) pq.push(make_pair(G[0][i].cost, G[0][i].to));
  while (S.size() < N) {
    pair<int, int> temp_pair = pq.top();
    pq.pop();
    if (S.find(temp_pair.second) != S.end()) continue;
    S.insert(temp_pair.second);
    fans += temp_pair.first;
    rep(i, G[temp_pair.second].size()) pq.push(make_pair(G[temp_pair.second][i].cost, G[temp_pair.second][i].to));
  }
  cout << fans << endl;
  return 0;
}
