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
  int s, t, w;
  Edge (int s, int t, int w) : s(s), t(t), w(w) {}
};

typedef vector<Edge> Edges;

int main() {
  int V, E, r;
  cin >> V >> E >> r;
  Edges Es;
  int s, t, d;
  int dist[V];
  bool v_flg[V];
  fill(v_flg, v_flg+V, false);
  fill(dist, dist+V, MOD);
  dist[r] = 0;
  v_flg[r] = true;
  rep(i, E) {
    cin >> s >> t >> d;
    Es.push_back(Edge(s, t, d));
  }
  int flg = true;
  int temp = 0;
  while (flg && (temp++ < V)) {
    flg = false;
    rep(i, E) {
      if (dist[Es[i].t] > dist[Es[i].s] + Es[i].w && v_flg[Es[i].s]) {
        dist[Es[i].t] = dist[Es[i].s] + Es[i].w;
        flg = true;
        v_flg[Es[i].t] = true;
      }
    }
  }
  if (temp > V) cout << "NEGATIVE CYCLE" << endl;
  else {
    rep(i, V) {
      if (!v_flg[i]) cout << "INF" << endl;
      else cout << dist[i] << endl;
    }
  }
  // source code
  return 0;
}
