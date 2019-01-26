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
  int a[N], b[N];
  int temp;
  rep(i, N) {
    cin >> temp;
    a[i] = temp;
    b[i] = MOD;
  }
  b[0] = 0;
  b[1] = abs(a[0] - a[1]);
  if (N == 2) {
    cout << b[1] << endl;
    return 0;
  }
  repd(i, 2, N) {
    b[i] = min(b[i-2] + abs(a[i] - a[i-2]), b[i-1] + abs(a[i] - a[i-1]));
  }
  cout << b[N-1] << endl;
  return 0;
}
