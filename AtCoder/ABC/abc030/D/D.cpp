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

int main() {
  int N, a;
  cin >> N >> a;
  LL k, temp_k, cur_turn;
  string S;
  cin >> S;
  k = MOD;
  if (S.length() < 10) {
    k = 0;
    rep(i, S.length()) {
      k *= 10;
      k += S[i] - '0';
    }
  }
  if (debug_mode) cout << k << endl;
  // cin >> k;
  int b[N+1];
  repd(i, 1, N+1) cin >> b[i];
  int ftime[N+1];
  fill(ftime, ftime+N+1, MOD);
  int loop[N+1];
  fill(loop, loop+N+1, MOD);
  temp_k = k;
  int cur_head = a;
  if (debug_mode) cout << "1 cur_head: " << cur_head << ", b[cur_head]: "<< b[cur_head] << endl;
  cur_turn = 0;
  while (k > cur_turn) {
    if (ftime[cur_head] < MOD) {
      if (loop[cur_head] == MOD) {
        loop[cur_head] = cur_turn - ftime[cur_head];
      }
      if (loop[cur_head] <= k-cur_turn) {
        // cur_turn += ((k-cur_turn) / loop[cur_head]) * loop[cur_head];
        if (debug_mode) {
          if (k - (k - cur_turn) % loop[cur_head] != ((k-cur_turn) / loop[cur_head]) * loop[cur_head] + cur_turn) {
            cout << "something wrong" << endl;
          }
        }
        if (k == MOD) {
          k = 0;
          rep(i, S.length()) {
            k *= 10;
            k += S[i] - '0';
            k %= loop[cur_head];
          }
          if (k < cur_turn) k += loop[cur_head];
        } else cur_turn = k - (k - cur_turn) % loop[cur_head];
        continue;
      } else if (loop[cur_head] < MOD) {
        cur_head = b[cur_head];
        if (debug_mode) cout << "2 cur_head: " << cur_head << ", b[cur_head]: "<< b[cur_head] << endl;
        cur_turn++;
      } else {
        cout << "something wrong" << endl;
      }
    } else {
      ftime[cur_head] = cur_turn;
      if (debug_mode) cout << "3 cur_head: " << cur_head << ", b[cur_head]: "<< b[cur_head] << endl;
      cur_head = b[cur_head];
      cur_turn++;
    }
  }
  cout << cur_head << endl;
  return 0;
}
