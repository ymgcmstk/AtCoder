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
  Edge (int to, int cost) : to(to), cost(cost) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

vector<int> dijkstra(Graph G, int start=0, int end=-1, bool is_directed=true) {
  if (!is_directed) {
    int edge_num[G.size()];
    rep(i, G.size()) edge_num[i] = G[i].size();
    rep(i, G.size()) rep(j, edge_num[i]) G[G[i][j].to].push_back(Edge(i, G[i][j].cost));
  }
  vector<int> d(G.size());
  fill(d.begin(), d.end(), MOD);
  d[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  rep(i, G[start].size()) pq.push(make_pair(G[start][i].cost, G[start][i].to));
  set<int> S;
  S.insert(start);
  while (S.size() < G.size() && pq.size() > 0) {
    pair<int, int> temp_p = pq.top();
    pq.pop();
    if (S.find(temp_p.second) != S.end()) continue;
    S.insert(temp_p.second);
    d[temp_p.second] = temp_p.first;
    rep(i, G[temp_p.second].size()) {
      if (S.find(G[temp_p.second][i].to) != S.end()) continue;
      pq.push(make_pair(G[temp_p.second][i].cost + d[temp_p.second], G[temp_p.second][i].to));
    }
    if (S.find(end) != S.end()) break;
  }
  return d;
}

bool check_distance(string s1, string s2) {
  char cur_num = 0;
  rep(i, s1.length()) {
    if (s1[i] != s2[i]) cur_num++;
    if (cur_num > 1) return false;
  }
  return true;
}


int main() {
  int N;
  string cur_str;
  vector<int> distance;
  vector<string> words;
  cin >> cur_str;
  words.push_back(cur_str);
  cin >> cur_str;
  words.push_back(cur_str);

  cin >> N;
  rep(i, N) {
    cin >> cur_str;
    words.push_back(cur_str);
  }
  Graph word_graph;
  rep(i, N+2) {
    Edges cur_edges;
    rep(j, N+2) {
      if (i == j) continue;
      if (check_distance(words[i], words[j])) cur_edges.push_back(Edge(j, 1));
    }
    word_graph.push_back(cur_edges);
  }


  distance = dijkstra(word_graph, 0, 1);
  if (distance[1] >= 0) {
    stack<string> ss;
    int cur_dist = distance[1];
    ss.push(words[0]);
    int ind, word_ind;
    word_ind = 0;
    while (cur_dist > 0) {
      ind = 0;
      while (distance[word_graph[word_ind][ind].to] != cur_dist-1) ind++;
      word_ind = word_graph[word_ind][ind].to;
      ss.push(words[word_ind]);
      cur_dist--;
    }
    cout << distance[1] << endl;
    while (ss.size() > 0) {
      cout << ss.top() << endl;
      ss.pop();
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
