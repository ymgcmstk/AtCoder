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

int GCD(int N, int M) {
  int n1 = max(N, M);
  int n2 = min(N, M);
  while (true) {
    if (n1 % n2 == 0) return n2;
    n1 %= n2;
    if (n2 % n1 == 0) return n1;
    n2 %= n1;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  int gcd = GCD(N, M);
  int cur_n = N / gcd;
  int cur_m = M / gcd;
  if (cur_n == 1) {
    cout << "1 0" << endl;
    return 0;
  }
  if (cur_m == 1) {
    cout << "0 1" << endl;
    return 0;
  }
  // 1.
  int cur_x = 0;
  int cur_y = 1;
  while (true) {
    cur_x = - (cur_m * cur_y) / cur_n;
    cout << cur_x << ' ' << cur_y << endl;
    if (cur_x * cur_n + cur_y * cur_m == 1) break;
    cur_y = - (cur_n * cur_x) / cur_m;
    cout << cur_x << ' ' << cur_y << endl;
    if (cur_x * cur_n + cur_y * cur_m == 1) break;
    return 0;
  }
  // 2.
  cout << cur_x << ' ' << cur_y << endl;
  return 0;
}
