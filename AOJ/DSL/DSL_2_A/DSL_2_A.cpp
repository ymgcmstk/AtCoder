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

int rmq(int * S, int cur, int cur_l, int cur_r, int left, int right) {
  /*
  cout << "S[cur]: " << S[cur] << ", (left <= cur_l && cur_r <= right): " << (left <= cur_l && cur_r <= right) << ", (cur_l > right || left < cur_r): "
       << (cur_l > right || left > cur_r) << ", cur: "
       << cur << ", cur_l: " << cur_l
       << ", cur_r: " << cur_r << ", left: " << left << ", right: " << right << endl;
  */
  if (left <= cur_l && cur_r - 1 <= right) return S[cur];
  else if (cur_l > right || left > cur_r - 1) return ((1 << 31) - 1);
  else return min(rmq(S, 2 * cur, cur_l, (cur_l + cur_r) / 2, left, right), rmq(S, 2 * cur + 1, (cur_l + cur_r) / 2, cur_r, left, right));
}
void print(int * S, int s_temp) {
  int cur = 1;
  cout << "print tree" << endl;
  repd(i, 1, s_temp) {
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
  int c, x, y;
  int n_bit = 0;
  int INF = (1 << 31) - 1;
  while ((N - 1)>> n_bit > 0) n_bit++;
  int s_len = 1 << (1+n_bit);
  int S[s_len];
  fill(S, S+s_len, INF);
  rep(i, Q) {
    cin >> c >> x >> y;
    if (c == 0) {
      int cur = s_len / 2 + x;
      S[cur] = y;
      while (cur > 1) {
        cur /= 2;
        if (S[cur] == min(S[cur * 2], S[cur * 2 + 1])) {
          break;
        } else {
          S[cur] = min(S[2 * cur], S[2 * cur + 1]);
        }
      }
    } else {
      /*
      cout << rmq(S, 1, 0, s_len/2, x, y) << " ("
           << x << ", "
           << y << ')' << endl;*/
      cout << rmq(S, 1, 0, s_len/2, x, y) << endl;
    }
  }
  // print(S, s_len);
  return 0;
}
