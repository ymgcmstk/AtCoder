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

typedef vector<pair<int, int> > VPII;
typedef vector<VPII> VVPII;

int main() {
  int V, E, r;
  cin >> V >> E >> r;
  int dist[V];
  fill(dist, dist+V, MOD);
  VVPII vvpii;
  rep(i, V) vvpii.push_back(VPII());
  int s, t, d;
  rep(i, E) {
    cin >> s >> t >> d;
    vvpii[s].push_back(make_pair(d, t));
  }
  set<int> S;
  dist[r] = 0;
  S.insert(r);
  priority_queue<pair<int, int>, VPII, greater<pair<int, int> > > pq;
  rep(i, vvpii[r].size()) pq.push(vvpii[r][i]);
  int next;
  pair<int, int > pii;
  int sum = 0;
  while (S.size() < V && pq.size() > 0) {
    pii = pq.top();
    pq.pop();
    next = pii.second;
    if (S.find(next) != S.end()) continue;
    S.insert(next);
    dist[next] = pii.first;
    rep(i, vvpii[next].size()) pq.push(make_pair(vvpii[next][i].first+dist[next], vvpii[next][i].second));
  }
  rep(i, V) {
    if (dist[i] == MOD) {
      cout << "INF" << endl;
    } else {
          cout << dist[i] << endl;
    }
  }




  return 0;
}
