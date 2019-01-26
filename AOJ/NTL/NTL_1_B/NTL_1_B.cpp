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

int main() {
  LL N, M;
  cin >> M >> N;
  LL ans = 1;
  LL temp = M;
  int cur_targ = 0;
  while ((1 << cur_targ) <= N) {
    if (((1 << cur_targ) & N) > 0) ans = (ans * temp) % MOD;
    temp = (temp * temp) % MOD;
    cur_targ++;
  }
  cout << ans << endl;
  return 0;
}
