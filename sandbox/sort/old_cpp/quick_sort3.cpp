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
#define BN 1000000007
using namespace std;

template <typename T>
void output(T a, int precision) {
  if(precision > 0){
    cout << setprecision(precision)  << a << "\n";
  } else {
    cout << a << "\n";
  }
}

template <typename T> vector<T> partition(vector<T> b, int* mid , int left, int right){
  int cur = left - 1;
  repd(i, left, right-1) {
    if (b[i] < b[right-1]) swap(b[i], b[++cur]);
  }
  swap(b[++cur], b[right-1]);
  *mid = cur;
  return b;
}

template <typename T> vector<T> quick_sort(vector<T> b, int left, int right) {
  int mid;
  if (right - left < 2) return b;
  b = partition(b, &mid, left, right);
  b = quick_sort(b, left, mid);
  b = quick_sort(b, mid+1, right);
  return b;
}

int main() {
  vector<int> A;
  vector<int> B;
  int N = 1000;
  rep(i, N)A.push_back(i);
  random_shuffle(A.begin(), A.end());
  rep(i, N)B.push_back(A[i]);
  // --------

  B = quick_sort(B, 0, N);

  // --------
  sort(A.begin(), A.end());
  bool flg = true;
  rep(i, N) {
    if (A[i] != B[i]) {
      cout << "error" << endl;
      rep(j, N) cout << B[j] << endl;
      flg = false;
      break;
    }
  }
  if (flg) cout << "success" << endl;
  return 0;
}
