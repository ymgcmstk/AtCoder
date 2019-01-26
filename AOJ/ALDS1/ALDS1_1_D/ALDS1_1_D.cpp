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
  int temp;
  int cur_max, cur_min;
  vector<int> future_max(N), past_min(N), input(N);
  rep(i, N) cin >> input[i];
  future_max[N-1] = input[N-1];
  past_min[0] = input[0];
  rep(i, N-1) {
    future_max[N-2-i] = max(future_max[N-1-i], input[N-2-i]);
    past_min[i+1] = min(past_min[i], input[i+1]);
  }
  int ans = -MOD;
  rep(i, N-1) {
    ans = max(ans, future_max[i+1] - past_min[i]);
  }
  cout << ans << endl;
  return 0;
}
