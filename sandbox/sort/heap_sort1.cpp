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


void maxHeapify(vector<int> &B, int n, int end) {
  if (end < 2 * n) return;
  else if (end == 2 * n) {
    if (B[2*n] > B[n]) swap(B[2*n], B[n]);
    return;
  }
  int max_child;
  if (B[2*n] > B[2*n+1]) max_child = 2 * n;
  else max_child = 2 * n + 1;
  if (B[max_child] > B[n]) {
    swap(B[max_child], B[n]);
    maxHeapify(B, max_child, end);
  }
}

void heap_sort(vector<int> &B) {
  B.insert(B.begin(), -1);
  mrepd(i, 1, B.size()) {
    maxHeapify(B, i, B.size()-1);
  }
  mrepd(i, 1, B.size()) {
    swap(B[1], B[i]);
    maxHeapify(B, 1, i-1);
  }
  B.erase(B.begin());
}

int main() {
  int N = 1000;
  vector<int> A, B;
  rep(i, N)A.push_back(i);
  random_shuffle(A.begin(), A.end());
  rep(i, N)B.push_back(A[i]);
  // --------

  heap_sort(B);

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
