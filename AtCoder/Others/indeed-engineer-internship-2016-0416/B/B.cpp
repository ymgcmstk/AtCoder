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
  int N;
  cin >> N;
  int num[N];
  bool flg[N];
  fill(flg, flg+N, false);
  rep(i, N) cin >> num[i];
  rep(i, N) num[i]--;
  int cur_ind = 0;
  int ans = 0;
  int next_ind;
  while (cur_ind < N) {
    if (flg[cur_ind]) {
      cur_ind++;
      continue;
    }
    ans += 1;
    next_ind = cur_ind;
    while (!flg[next_ind]) {
      flg[next_ind] = true;
      next_ind = num[next_ind];
    }
    cur_ind++;
  }
  cout << ans << endl;
  return 0;
}
