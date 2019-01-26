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
  int A, B;
  cin >> A >> B;
  int diff = abs(A - B);
  int ans = 0;
  ans += (diff) / 10;
  diff %= 10;
  if (diff > 7) {
    diff = abs(diff - 10);
    ans += 1;
  }
  ans += diff / 5;
  diff %= 5;
  if (diff > 3) {
    diff = abs(diff - 5);
    ans += 1;
  }
  ans += diff;
  cout << ans << endl;
  return 0;
}