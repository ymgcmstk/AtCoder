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

bool debug_mode = false;


struct Edge {
  int to, cost;
  bool B;
  Edge (int to, int cost, bool B) : to(to), cost(cost), B(B) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;


typedef pair<int, pair<int, int> > triint;

class MyCompare {
public:
  enum Mode {
    MODE_NORMAL,
    MODE_REVERSE,
  };
public:
  explicit MyCompare(Mode mode = MODE_NORMAL) : mMode(mode) {}
  inline bool operator()(const triint a, const triint b) const
  {
    int temp_a = a.second.second;
    temp_a = temp_a * (temp_a - 1) / 2;
    int temp_b = b.second.second;
    temp_b = temp_b * (temp_b - 1) / 2;
    return mMode == MODE_NORMAL ? a.first + temp_a > b.first + temp_b : a.first + temp_a < b.first + temp_b;
  }
private:
  Mode mMode;
};

const int BIGNUM = 100000000;

int main() {
  int N, M;
  cin >> N >> M;
  int B_max = int(pow((N-1) * 2, 0.5) + 0.5);
  vector<int> min_dist(N, BIGNUM);
  min_dist[0] = 0;
  vector< vector<int> > dist;
  rep(i, N) {
    dist.push_back(vector<int>(B_max+1));
    fill(dist[i].begin(), dist[i].end(), BIGNUM);
  }

  dist[0][0] = 0;
  vector<int> C(N);
  vector<int> A(N), B(N);
  Graph graph;
  rep(i, N) graph.push_back(Edges());
  rep(i, M) {
    cin >> C[i];
    cin >> A[i] >> B[i];
    graph[A[i]].push_back(Edge(B[i], 1, bool(C[i])));
    graph[B[i]].push_back(Edge(A[i], 1, bool(C[i])));
    if (debug_mode) {
      cout << A[i] << ' ' << B[i] << endl;
      cout << graph[A[i]].size() << endl;
      cout << graph[B[i]].size() << endl;
      cout << "0: " << graph[0].size() << endl;
    }
  }
  priority_queue<triint, vector<triint>, MyCompare > pq;
  rep(i, graph[0].size()) {
    if (debug_mode) cout << "i: " << i << ' ' << graph[0][i].to << ' ' << graph[0][i].cost << ' ' << graph[0][i].B << endl;
    if (graph[0][i].B) pq.push(make_pair(graph[0][i].cost, make_pair(graph[0][i].to, 1)));
    else pq.push(make_pair(graph[0][i].cost, make_pair(graph[0][i].to, 0)));
  }
  set<int> S;
  S.insert(0);
  int cur_layer, cur_node;

  while (S.size() < graph.size() && pq.size() > 0) {

    triint temp_p = pq.top();
    pq.pop();
    cur_layer = temp_p.second.second;
    cur_node = temp_p.second.first;
    if (dist[cur_node][cur_layer] < BIGNUM) continue;
    // cout << cur_node << ' ' << cur_layer << ' ' << temp_p.first << endl;
    S.insert(cur_node);
    dist[cur_node][cur_layer] = temp_p.first;
    rep(i, graph[cur_node].size()) {
      int add = 0;
      if (graph[cur_node][i].B) add = 1;
      if (cur_layer+add >= B_max) continue;
      if (dist[graph[cur_node][i].to][cur_layer+add] < BIGNUM) continue;
      pq.push(make_pair(graph[cur_node][i].cost + dist[cur_node][cur_layer],
                        make_pair(graph[cur_node][i].to, cur_layer+add)));
    }
  }
  rep(i, N) {
    min_dist[i] = dist[i][0];
    // cout << "min_dist: " << i << ' ' << min_dist[i] << endl;
    rep(j, B_max) {
      min_dist[i] = min(min_dist[i], dist[i][j] + j * (j-1) / 2);
    }
    // cout << "min_dist2: " << i << ' ' << min_dist[i] << endl;
    cout << min_dist[i] << endl;
  }
  return 0;
}
