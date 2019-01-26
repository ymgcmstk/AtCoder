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

void merge_sort(vector<int> &A, int start, int end) {
  if (end - start == 1) {
    return;
  }
  int mid = (end + start) / 2;
  merge_sort(A, start, mid);
  merge_sort(A, mid, end);
  int old_vals[end - start];
  rep(i, end-start) {
    old_vals[i] = A[i + start];
  }
  int cur_left = start;
  int cur_right = mid;
  int cur_p = start;
  while (cur_left < mid && cur_right < end) {
    if (old_vals[cur_left - start] < old_vals[cur_right - start]) {
      A[cur_p] = old_vals[cur_left - start];
      cur_left++;
    } else {
      A[cur_p] = old_vals[cur_right - start];
      cur_right++;
    }
    cur_p++;
  }
  while (cur_left < mid) {
    A[cur_p] = old_vals[cur_left - start];
    cur_left++;
    cur_p++;
  }
  while (cur_right < end) {
    A[cur_p] = old_vals[cur_right - start];
    cur_right++;
    cur_p++;
  }
}

int main() {
  int N = 20;
  vector<int> A, B;
  rep(i, N)A.push_back(i);
  random_shuffle(A.begin(), A.end());
  rep(i, N)B.push_back(A[i]);
  // --------
  merge_sort(B, 0, 20);
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
