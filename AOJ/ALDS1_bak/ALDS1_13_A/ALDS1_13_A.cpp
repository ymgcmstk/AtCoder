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

typedef pair<int, int> pii;

int get_next(pii prev_q) {
  return prev_q.first * 8 + prev_q.second + 1;
}

void print_chess_board(vector<vector<bool> > &chess_board){
  rep(i, 8) {
    rep(j, 8) {
      if (chess_board[i][j]) cout << 'Q';
      else cout << '.';
    }
    cout << endl;
  }
}

void pop_all(vector<vector<int> > &Ss) {
  rep(i, 4) Ss[i].erase(Ss[i].end()-1);
}

void push_all(pii q, vector<vector<int> > &Ss) {
  int p = q.first;
  int s = q.second;
  Ss[0].push_back(p);
  Ss[1].push_back(s);
  Ss[2].push_back(p+s);
  Ss[3].push_back(p-s);
}

int check_all(pii q, vector<vector<int> > &Ss) {
  if (find(Ss[0].begin(), Ss[0].end(), q.first) != Ss[0].end()) return false;
  if (find(Ss[1].begin(), Ss[1].end(), q.second) != Ss[1].end()) return false;
  if (find(Ss[2].begin(), Ss[2].end(), q.first+q.second) != Ss[2].end()) return false;
  if (find(Ss[3].begin(), Ss[3].end(), q.first-q.second) != Ss[3].end()) return false;
  return true;
}

bool try_arranging(vector<vector<int> > &Ss, stack<pii> &Qs) {
  if (Qs.size() == 9) return true;
  int starting = get_next(Qs.top());
  pii cur_pair;
  repd(i, starting, 64) {
    cur_pair = make_pair(i/8, i%8);
    if (check_all(cur_pair, Ss)) {
      push_all(cur_pair, Ss);
      Qs.push(cur_pair);
      if (try_arranging(Ss, Qs)) return true;
      pop_all(Ss);
      Qs.pop();
    }
  }
  return false;
}

bool try_arranging_stack(vector<vector<int> > &Ss, stack<pii> &Qs) {
  stack<int> S;
  int starting = 0;
  while (Qs.size() < 9) {
    pii cur_pair;
    bool temp_flg = true;
    repd(i, starting, 64) {
      cur_pair = make_pair(i/8, i%8);
      if (check_all(cur_pair, Ss)) {
        push_all(cur_pair, Ss);
        Qs.push(cur_pair);
        S.push(i);
        temp_flg = false;
        starting = i + 1;
      }
    }
    if (temp_flg) {
      pop_all(Ss);
      Qs.pop();
      starting = S.top() + 1;
      S.pop();
    }
  }
  return true;
}

int main() {
  int        N;
  cin >> N;
  vector<vector<bool> > chess_map(8);
  rep(i, 8) chess_map[i] = vector<bool>(8);
  rep(i, 8) fill(chess_map[i].begin(), chess_map[i].end(), false);
  int        p, s;
  vector<vector<int> > Ss(4);
  stack<pii> Qs;
  pii        cur_pair;
  rep(i, N) {
    cin >> p >> s;
    chess_map[p][s] = true;
    pii cur_pair        = make_pair(p, s);
    push_all(cur_pair, Ss);
    Qs.push(cur_pair);
  }
  pii sentinel = make_pair(-1, 7);
  Qs.push(sentinel);

  try_arranging_stack(Ss, Qs);
  while (Qs.top().first >= 0) {
    pii this_q = Qs.top(); Qs.pop();
    chess_map[this_q.first][this_q.second] = true;
  }

  print_chess_board(chess_map);
  return 0;
}
