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

typedef pair<int, int> pii;
typedef pair<double, pii> pdpii;
// typedef priority_queue<pdpii, vector<pdpii> > pqpdpii;
typedef priority_queue<pdpii> pqpdpii;

const int d_x[] = {0, 1, 0, -1};
const int d_y[] = {1, 0, -1, 0};

void push_to_PQ(pdpii cur_path, vector<vector<double> >& map_max, pqpdpii& PQ, vector<vector<int> >& map_br) {
}

void print_mapd(vector<vector<double> > map1) {
  rep(i, map1.size()) {
    rep(j, map1[0].size()) cout << map1[i][j];
    cout << endl;
  }
}

void print_mapi(vector<vector<int> > map1) {
  rep(i, map1.size()) {
    rep(j, map1[0].size()) cout << map1[i][j];
    cout << endl;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<double> > map_max(N);
  vector<vector<int> > map_br(N);
  rep(i, N) {
    map_max[i] = vector<double>(M);
    fill(map_max[i].begin(), map_max[i].end(), -2);
    map_br[i] = vector<int>(M);
  }
  pqpdpii PQ;
  int s_i, s_j;
  int g_i, g_j;
  string::size_type s_index;
  rep(i, N) {
    string temp_str;
    cin >> temp_str;
    rep(j, M) {
      if (temp_str[j] == 's') {
        map_br[i][j] = 10;
        s_i = i;
        s_j = j;
      } else if (temp_str[j] == 'g') {
        map_br[i][j] = 10;
        g_i = i;
        g_j = j;
      } else if (temp_str[j] == '#') map_br[i][j] = -1;
      else map_br[i][j] = int(temp_str[j] - '0');
    }
  }
  if (debug_mode) {
    print_mapd(map_max);
    print_mapi(map_br);
    cout << s_i << ' ' << s_j << endl;
  }

  // push_to_PQ(make_pair(100, make_pair(g_i, g_j)), map_max, PQ, map_br);
  pdpii cur_pid;
  int cur_i, cur_j;
  int this_i, this_j;
  double br;
  double cur;
  PQ.push(make_pair(100, make_pair(g_i, g_j)));
  while (PQ.size() > 0 && map_max[s_i][s_j] < 0) {
    cur_pid = PQ.top(); PQ.pop();
    cur_i = cur_pid.second.first;
    cur_j = cur_pid.second.second;
    if (map_max[cur_i][cur_j] > -1) {
      continue;
    }
    map_max[cur_i][cur_j] = cur_pid.first;
    br = cur_pid.first * 0.99;
    rep(i, 4) {
      this_i = cur_i + d_x[i];
      this_j = cur_j + d_y[i];
      if (!(this_i >= 0 && this_i < map_max.size() && this_j >= 0 && this_j < map_max[0].size())) continue;
      if (map_max[this_i][this_j] > -1) continue;
      cur = min(br, double(map_br[this_i][this_j]));
      PQ.push(make_pair<double, pii>(cur, make_pair(this_i, this_j)));
    }
  }
  if (map_max[s_i][s_j] < 0) {
    cout << -1 << endl;
  } else {
    cout << setprecision(15) << map_max[s_i][s_j] << endl;
  }
  return 0;
}
