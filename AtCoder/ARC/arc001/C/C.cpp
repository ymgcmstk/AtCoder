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

bool chess_board[8][8];
bool Q_x[8], Q_y[8], Q_xpy[16], Q_xmy[16];

void add_Q(int q_x, int q_y) {
  Q_x[q_x] = true;
  Q_y[q_y] = true;
  Q_xpy[q_x + q_y] = true;
  Q_xmy[q_x - q_y + 7] = true;
  chess_board[q_x][q_y] = true;
}

void remove_Q(int q_x, int q_y) {
  if (!Q_x[q_x]) {
    cout << "ERROR" << endl;
    cout << q_x << ' ' << q_y << endl;
    exit(1);
  }
  if (!Q_y[q_y]) {
    cout << "ERROR" << endl;
    cout << q_x << ' ' << q_y << endl;
    exit(1);
  }
  if (!Q_xpy[q_x + q_y]) {
    cout << "ERROR" << endl;
    cout << q_x << ' ' << q_y << endl;
    exit(1);
  }
  if (!Q_xmy[q_x - q_y + 7]) {
    cout << "ERROR" << endl;
    cout << q_x << ' ' << q_y << endl;
    exit(1);
  }
  if (!chess_board[q_x][q_y]) {
    cout << "ERROR" << endl;
    cout << q_x << ' ' << q_y << endl;
    exit(1);
  }
  Q_x[q_x] = false;
  Q_y[q_y] = false;
  Q_xpy[q_x + q_y] = false;
  Q_xmy[q_x - q_y + 7] = false;
  chess_board[q_x][q_y] = false;
}

bool can_set_Q(int q_x, int q_y) {
  if (!Q_x[q_x] && !Q_y[q_y] && !Q_xpy[q_x + q_y] && !Q_xmy[q_x - q_y + 7]) return true;
  else return false;
}

bool search_new_Q(int Qnum, int s_ij) {
  if (Qnum == 8) return true;
  int start_j;
  repd(i, s_ij / 8, 8) {
    if (i == (s_ij / 8)) start_j = s_ij % 8;
    else start_j = 0;
    repd(j, start_j, 8) {
      if (can_set_Q(i, j)) {
        add_Q(i, j);
        if (search_new_Q(Qnum + 1, i * 8 + j + 1)) return true;
        remove_Q(i, j);
      }
    }
  }
  return false;
}

void display_board() {
  rep(i, 8) {
    rep(j, 8) {
      cout << (chess_board[i][j] ? 'Q' : '.');
    }
    cout << endl;
  }
}

int main() {
  string S;
  fill(Q_x, Q_x+8, false);
  fill(Q_y, Q_y+8, false);
  fill(Q_xpy, Q_xpy+16, false);
  fill(Q_xmy, Q_xmy+16, false);
  int Qnum = 0;
  int first_flg = false;
  rep(i, 8) {
    cin >> S;
    rep(j, 8) {
      chess_board[i][j] = (S[j] == 'Q');
      if (S[j] == 'Q') {
        if (!can_set_Q(i, j)) first_flg = true;
        Qnum++;
        add_Q(i, j);
      }
    }
  }

  /*
  rep(i, 8) fill(chess_board[i], chess_board[i]+8, false);
  int Qnum;
  cin >> Qnum;
  rep(i, Qnum) {
    int x, y;
    cin >> x >> y;
    add_Q(x, y);
  }
  */
  if (search_new_Q(Qnum, 0) && !first_flg) display_board();
  else cout << "No Answer" << endl;
  return 0;
}
