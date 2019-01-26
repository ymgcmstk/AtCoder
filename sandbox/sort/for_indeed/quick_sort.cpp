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

void quick_sort(vector<int> &A, int start, int end) {
  if (end - start <= 1) return;
  int cur_pivot = start + 1;
  int cur_mid = start + 1;
  while (cur_pivot < end) {
    if (A[cur_pivot] < A[start]) {
      swap(A[cur_pivot], A[cur_mid]);
      cur_mid++;
    }
    cur_pivot++;
  }
  swap(A[cur_mid-1], A[start]);
  quick_sort(A, start, cur_mid-1);
  quick_sort(A, cur_mid, end);
}

int main() {
  int N = 20;
  vector<int> A, B;
  rep(i, N)A.push_back(i);
  random_shuffle(A.begin(), A.end());
  rep(i, N)B.push_back(A[i]);
  // --------

  quick_sort(B, 0, 20);

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
