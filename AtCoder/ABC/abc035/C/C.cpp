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
  int N, Q;
  int l, r;
  cin >> N >> Q;
  bool rev[N+1];
  fill(rev, rev+N+1, false);
  rep(i, Q) {
    cin >> l >> r;
    rev[l-1] = !rev[l-1];
    rev[r] = !rev[r];
  }
  bool cur_num = false;
  rep(i, N) {
    if (rev[i]) cur_num = !cur_num;
    if (cur_num) cout << '1';
    else cout << '0';
  }
  cout << endl;
  return 0;
}
