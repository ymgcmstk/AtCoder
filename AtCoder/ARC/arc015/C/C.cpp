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

bool debug_mode = true;


struct Edge {
  int to, rev;
  double cost;
  Edge (int to, float cost) : to(to), cost(cost) {}
  Edge (int to, float cost, int rev) : to(to), cost(cost), rev(rev) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void c_dfs(Graph &G, vector<double> &vd, int start) {
  rep(i, G[start].size()) {
    if (vd[G[start][i].to] > 0) continue;
    vd[G[start][i].to] = G[start][i].cost * vd[start];
    c_dfs(G, vd, G[start][i].to);
  }
}

double dfs(Graph G, int &i_min, int &i_max) {
  vector<double> vd(G.size());
  fill(vd.begin(), vd.end(), -1);
  vd[0] = 1;
  rep(i, G[0].size()) {
    vd[G[0][i].to] = G[0][i].cost;
    c_dfs(G, vd, G[0][i].to);
  }
  double d_max = vd[0];
  double d_min = vd[0];
  i_min = 0;
  i_max = 0;
  repd(i, 1, vd.size()) {
    if (d_max < vd[i]) {
      d_max = vd[i];
      i_max = i;
    }
    if (d_min > vd[i]) {
      d_min = vd[i];
      i_min = i;
    }
  }
  return d_max / d_min;
}

int main() {
  int N;
  cin >> N;
  map<string, int> msi;
  vector<string> bef(N), aft(N);
  vector<double> dist(N);
  vector<int> numer(N);
  vector<int> denom(N);
  rep(i, N) cin >> bef[i] >> dist[i] >> aft[i];
  set<string> ss;
  rep(i, N) {
    ss.insert(bef[i]);
    ss.insert(aft[i]);
  }
  vector<string> v2s(ss.begin(), ss.end());
  map<string, int> g2i;
  map<int, string> i2g;
  Graph G;
  rep(i, v2s.size()) {
    g2i[v2s[i]] = i;
    i2g[i] = v2s[i];
    G.push_back(Edges());
  }
  rep(i, N) {
    G[g2i[bef[i]]].push_back(Edge(g2i[aft[i]], double(1/dist[i])));
    G[g2i[aft[i]]].push_back(Edge(g2i[bef[i]], double(dist[i])));
  }
  int i_min, i_max;
  double res = dfs(G, i_min, i_max);
  cout << '1' << i2g[i_max] << '=' << int(round(res)) << i2g[i_min] << endl;
  return 0;
}
