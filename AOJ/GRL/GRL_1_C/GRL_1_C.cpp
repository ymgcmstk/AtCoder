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
#define MOD 1980000000
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

int main() {
  int V, E;
  cin >> V >> E;
  int dist[V][V];
  bool flg[V][V];
  rep(i, V) {
    fill(dist[i], dist[i]+V, MOD);
    fill(flg[i], flg[i]+V, false);
    dist[i][i] = 0;
    flg[i][i] = true;
  }
  int s, t, d;
  rep(i, E) {
    cin >> s >> t >> d;
    dist[s][t] = d;
    flg[s][t] = true;
  }
  rep(k, V) rep(i, V) rep(j, V) {
    if (!(flg[i][k] && flg[k][j])) continue;
    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    flg[i][j] = true;
  }
  rep(i, V) {
    if (dist[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  rep(i, V) {
    rep(j, V-1) {
      if (flg[i][j]) cout << dist[i][j] << ' ';
      else cout << "INF ";
    }
    if (flg[i][V-1]) cout << dist[i][V-1] << endl;
    else cout << "INF" << endl;
  }
  return 0;
}
