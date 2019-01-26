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
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  int ans = 0;
  int cur_min;
  int cur_ind;
  rep(i, N-1) {
    cur_min = A[i];
    cur_ind = i;
    repd(j, i+1, N) {
      if (cur_min > A[j]) {
        cur_min = A[j];
        cur_ind = j;
      }
    }
    if (cur_ind != i){
      ans += 1;
      swap(A[cur_ind], A[i]);
    }
  }
  rep(i, N-1) cout << A[i] << ' ';
  cout << A[N-1] << endl << ans << endl;
  return 0;
}
