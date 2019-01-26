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
  int cost, to;
  Edge(int to, int cost): cost(cost), to(to) {}
};

int main() {
  int N;
  cin >> N;
  int l_mat[N][N];
  vector< vector<Edge> > l_list;
  rep(i, N) l_list.push_back(vector<Edge>());
  int temp;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  set<int> S;
  rep(i, N) rep(j, N) {
    cin >> temp;
    if (temp >= 0) l_list[i].push_back(Edge(j, temp));
  }
  S.insert(0);
  rep(i, l_list[0].size()) pq.push(make_pair(l_list[0][i].cost, l_list[0][i].to));
  int fans = 0;
  while (pq.size() > 0) {
    pair<int, int> cur_p = pq.top();
    pq.pop();
    if (S.find(cur_p.second) == S.end()) {
      S.insert(cur_p.second);
      fans += cur_p.first;
      rep(i, l_list[cur_p.second].size()) pq.push(make_pair(l_list[cur_p.second][i].cost, l_list[cur_p.second][i].to));
    }
  }
  cout << fans << endl;

  return 0;
}
