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

vector<int> A;
vector<int> B;

void merge_two(int left, int right){
  int mid = (left + right) / 2;
  int len = right - left;
  int temp[len];
  int p, q;
  p = 0;
  q = 0;
  rep(i, len) {
    if ((B[left+p] < B[mid+q] || q >= right - mid) && p < mid-left) {
      temp[i] = B[left+p];
      p++;
    } else {
      temp[i] = B[mid+q];
      q++;
    }
  }
  rep(i, len) {
    B[i+left] = temp[i];
  }
}

void merge(int left, int right){
  if (left <= right - 2) {
    int mid = (left + right) / 2;
    merge(left, mid);
    merge(mid, right);
    merge_two(left, right);
  }
}

int main() {
  int N = 100;
  rep(i, N)A.push_back(i);
  random_shuffle(A.begin(), A.end());
  rep(i, N)B.push_back(A[i]);
  // --------
  merge(0, N);
  // --------
  sort(A.begin(), A.end());
  bool flg = true;
  rep(i, N) {
    if (A[i] != B[i]) {
      cout << "error" << endl;
      rep(j, N) cout << B[j] << ' ';
      flg = false;
      break;
    }
  }
  if (flg) cout << "success" << endl;
  return 0;
}
