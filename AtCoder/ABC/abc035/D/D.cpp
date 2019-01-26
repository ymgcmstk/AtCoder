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

bool debug_mode = false;

int main() {
  int N, M, T;
  cin >> N >> M >> T;
  int A[N];
  rep(i, N) cin >> A[i];
  int a[M], b[M], c[M];
  rep(i, M) cin >> a[i] >> b[i] >> c[i];
  rep(i, M) {
    a[i]--;
    b[i]--;
  }
  LL ans[T+1][N];
  rep(i, T+1) fill(ans[i], ans[i]+N, -MOD);
  ans[0][0] = 0;
  rep(i, T+1) {
    rep(j, M) {
      if (i + c[j] > T) continue;
      if (ans[i][a[j]] < 0) continue;
      ans[i + c[j]][b[j]] = max(ans[i + c[j]][b[j]], ans[i][a[j]]);
    }
    rep(j, N) {
      if (ans[i][j] < 0) continue;
      ans[i+1][j] = max(ans[i+1][j], ans[i][j] + A[j]);
    }
  }
  cout << ans[T][0] << endl;
  return 0;
}
