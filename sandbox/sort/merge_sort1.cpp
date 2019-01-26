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

void merge_sort(vector<int> &B, int left, int right) {
  if (right - left == 1) return;
  int mid = (left + right) / 2;
  merge_sort(B, left, mid);
  merge_sort(B, mid, right);
  vector<int> cache = vector<int>(right - left);
  // TODO
  int cur_l = left;
  int cur_r = mid;
  int cur_cache = 0;
  while (cur_l < mid && cur_r < right) {
    if (B[cur_l] <= B[cur_r]) {
      cache[cur_cache] = B[cur_l];
      cur_l++;
    } else {
      cache[cur_cache] = B[cur_r];
      cur_r++;
    }
    cur_cache++;
  }
  while (cur_l < mid) cache[cur_cache++] = B[cur_l++];
  while (cur_r < right) cache[cur_cache++] = B[cur_r++];
  rep(i, cache.size()) B[i+left] = cache[i];
}

int main() {
  int N = 1000;
  vector<int> A, B;
  rep(i, N)A.push_back(i);
  random_shuffle(A.begin(), A.end());
  rep(i, N)B.push_back(A[i]);
  // --------

  merge_sort(B, 0, B.size());

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
