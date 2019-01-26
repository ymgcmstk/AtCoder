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

int main() {
  int N;
  cin >> N;
  vector< vector< pair<int, int> > > Vs;
  int u, k, v, c;
  rep(i, N) Vs.push_back(vector< pair<int, int> >());
  rep(i, N) {
    cin >> u >> k;
    rep(j, k) {
      cin >> v >> c;
      Vs[u].push_back(make_pair(c, v));
    }
  }
  int d[N];
  fill(d, d + N, MOD);
  set<int> S;
  S.insert(0);
  d[0] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
  rep(i, Vs[0].size()) PQ.push(Vs[0][i]);

  while (S.size() < N) {
    pair<int, int> temp_p = PQ.top();
    PQ.pop();
    if (S.find(temp_p.second) != S.end()) continue;
    d[temp_p.second] = temp_p.first;
    S.insert(temp_p.second);
    rep(i, Vs[temp_p.second].size()) if (S.find(Vs[temp_p.second][i].second) == S.end()) PQ.push(make_pair(d[temp_p.second] + Vs[temp_p.second][i].first, Vs[temp_p.second][i].second));
  }
  rep(i, N) cout << i << ' ' << d[i] << endl;
  return 0;
}
