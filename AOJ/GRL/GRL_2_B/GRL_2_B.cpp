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
  int from, to, cost;
  Edge (int from, int to, int cost): from(from), to(to), cost(cost) {}
  Edge (int from, int cost): from(from), cost(cost) {
    to = -1;
  }
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int main() {
  int V, E, r;
  cin >> V >> E >> r;
  int s, t, w;
  Graph G;
  rep(i, V) G.push_back(Edges());
  rep(i, E) {
    cin >> s >> t >> w;
    if (t == r) continue;
    G[t].push_back(Edge(s, w));
  }
  int sum = 0;
  rep(i, G.size()) {
    int cur_min = MOD;
    if (i == r) continue;
    rep(j, G[i].size()) {
      cur_min = min(cur_min, G[i][j].cost);
    }
    sum += cur_min;
  }
  cout << sum << endl;
  return 0;
}
