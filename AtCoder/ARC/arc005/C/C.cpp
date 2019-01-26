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

typedef vector<vector<char> > vvc;
typedef vector<vector<bool> > vvb;
typedef pair<int, int> pii;

bool debug_mode = true;

const char WALL = '#';
const char S = 's';
const char G = 'g';
const char HALF_S = 'S';
const char HALF_G = 'G';
const char UNKNOWN = '.';

const int d_x[] = {0, 1, 0, -1};
const int d_y[] = {1, 0, -1, 0};

const int d_x2[] = {2, 1, 0, -1, -2, -1,  0,  1};
const int d_y2[] = {0, 1, 2,  1,  0, -1, -2, -1};

void show(vvc &town_map) {
  rep(i, town_map.size()) {
    rep(j, town_map[0].size()) {
      cout << town_map[i][j];
    }
    cout << endl;
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  vvc town_map(H);
  vvb visited(H);
  char temp;
  int start_i, start_j, goal_i, goal_j;
  priority_queue<pair<char, pair<int, int> > > PQ;
  rep(i, H) {
    town_map[i] = vector<char>(W);
    visited[i] = vector<bool>(W);
    fill(visited[i].begin(), visited[i].end(), false);
    rep(j, W) {
      cin >> temp;
      if (temp == S) {
        start_i = i;
        start_j = j;
        town_map[i][j] = UNKNOWN;
        PQ.push(make_pair(0, make_pair(i, j)));
      } else if (temp == G) {
        goal_i = i;
        goal_j = j;
        town_map[i][j] = UNKNOWN;
      } else {
        town_map[i][j] = temp;
      }
    }
  }
  pair<char, pair<int, int> > cur_p;
  int cur_x, cur_y;
  while (!PQ.empty()) {
    cur_p = PQ.top(); PQ.pop();
    cur_x = cur_p.second.first;
    cur_y = cur_p.second.second;
    if (visited[cur_x][cur_y]) continue;
    visited[cur_x][cur_y] = true;
    rep(i, 4) {
      cur_x = cur_p.second.first + d_x[i];
      cur_y = cur_p.second.second + d_y[i];
      if (cur_x < 0 || cur_x >= town_map.size()) continue;
      if (cur_y < 0 || cur_y >= town_map[i].size()) continue;
      if (visited[cur_x][cur_y]) continue;
      if (cur_x == goal_i && cur_y == goal_j) {
        cout << "YES" << endl;
        return 0;
      } else if (town_map[cur_x][cur_y] == UNKNOWN) {
        PQ.push(make_pair(cur_p.first, make_pair(cur_x, cur_y)));
      } else if (town_map[cur_x][cur_y] == WALL) {
        if (cur_p.first == -2) continue;
        PQ.push(make_pair(cur_p.first-1, make_pair(cur_x, cur_y)));
      } else {
        cout << "ERROR" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
