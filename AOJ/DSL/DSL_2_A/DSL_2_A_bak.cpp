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

int rmq(int * S, int cur, int depth, int left, int right, int c_d) {
  int temp = 1 << (depth - c_d);
  int t_left, t_right;
  t_left = (cur - (1 << (c_d - 1))) * temp + 1;
  t_right = (cur - (1 << (c_d - 1)) + 1) * temp + 1;
  // cout << cur << ' ' << S[cur] << ' ' << t_left << ' ' << t_right << endl;
  if ((left <= t_left && t_right < right)) return S[cur];
  else if ((1 << depth) <= cur) return MOD;
  else return min(rmq(S, cur*2, depth, left, right, c_d+1), rmq(S, cur*2+1, depth, left, right, c_d+1));
}

void print(int * S, int s_temp) {
  int cur = 1;
  cout << "print tree" << endl;
  repd(i, 1, s_temp+1) {
    cout << S[i] << ' ';
    if (i+1 == (1 << cur)) {
      cur++;
      cout << endl;
    }
  }
  cout << endl;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  int depth = 0;
  while (((N - 1) >> depth) != 0) depth++;
  depth++;
  int s_temp = 1 << depth;
  int S[s_temp];
  fill(S, S+s_temp, MOD);
  int c, x, y;
  int cur;
  rep(i, Q) {
    cin >> c >> x >> y;
    if (c == 0) {
      cur = x + s_temp / 2;
      while (cur > 0) {
        if (S[cur] < y && cur != x + s_temp / 2) {
          break;
        }
        S[cur] = y;
        cur = cur / 2;
      }
    } else {
      y++;
      cout << rmq(S, 1, depth, x, y, 1) << endl;
    }
  }
  // print(S, s_temp);
  return 0;
}
