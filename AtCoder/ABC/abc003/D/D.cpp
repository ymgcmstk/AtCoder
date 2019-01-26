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

template <typename T>
T nCm(T n, T m, T mod) {
  T ans;
  vector<T> pas;
  rep(i, n + 1) {
    if (i % 2 == 0) {
      pas.push_back(1);
      mrepd(j, 1, i / 2) pas[j] = (pas[j] + pas[j-1]) % mod;
      if (i > 0) pas[0] = pas[0] * 2 % mod;
    } else rep(j, i / 2) pas[j] = (pas[j] + pas[j+1]) % mod;
  }
  T C_left = min(m, n - m);
  return pas[pas.size()-C_left-1];
}

int main() {
  int R, C, X, Y, D, L;
  cin >> R >> C >> X >> Y >> D >> L;
  if (D + L != X * Y) return 0;
  LL ans = nCm(X*Y, min(D, L), MOD);
  ans = ans * (R - X + 1) % MOD;
  ans = ans * (C - Y + 1) % MOD;
  cout << ans << endl;
  return 0;
}
