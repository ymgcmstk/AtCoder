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
// #define MOD 1000000007
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

template <typename T>
T nCm(T n, T m, T mod) {
  if (n == 0) return 1;
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

LL count_ways(int x, int y, int T, int MOD) {
  int rem = T - x - y;
  if (rem == 0) return nCm(T, x, MOD);
  LL ans = 0;
  rep(i, rem / 2 + 1) {
    LL temp = nCm(x + i * 2, i, MOD) % MOD;
    LL temp2 = nCm(y + rem - i * 2, rem / 2- i, MOD) % MOD;
    LL temp3 = (temp * temp2) % MOD;
    ans += (nCm(T, x + i * 2, MOD) * temp3) % MOD;
  }
  return ans;
}

int main() {
  int N, T, MOD;
  cin >> N >> T >> MOD;
  vector<int> x(N);
  vector<int> y(N);
  vector<int> rem(N);
  bool flg = false;
  rep(i, N) {
    cin >> x[i] >> y[i];
    x[i] = abs(x[i]);
    y[i] = abs(y[i]);
    rem[i] = T - x[i] - y[i];
    if (rem[i] % 2 == 1) flg = true;
  }
  if (flg) {
    cout << 0 << endl;
    return 0;
  }
  LL ans = 1;
  rep(i, N) {
    ans *= count_ways(x[i], y[i], T, MOD);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
