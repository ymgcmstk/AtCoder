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

int length[1000003];

int main() {
  int N;
  cin >> N;
  fill(length, length+1000003, 0);
  int prev = 0;
  int prev_a = -1;
  int cur_a;
  int max_len = 0;
  rep(i, N) {
    cin >> cur_a;
    if (cur_a <= prev_a) {
      max_len = max(max_len, i - prev);
      length[i - prev] += 1;
      prev = i;
    }
    prev_a = cur_a;
  }
  max_len = max(max_len, N - prev);
  length[N - prev] += 1;
  LL ans = length[2];
  repd(i, 3, max_len+1) {
    if (length[i] == 0) continue;
    LL a = ((LL)i) * ((LL)(i-1)) / 2;
    // if (i % 2 == 0) ans += length[i] * (i / 2) * (i - 1);
    // else ans += (LL)(length[i] * ((i - 1) / 2) * i);
    ans += ((LL)(length[i])) * a;
  }
  cout << ans + N << endl;
  return 0;
}
