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

template <typename T> void print(vector<T> B){
  rep(i, B.size()) cout << B[i] << ' ';
  cout << endl;
}

template <typename T> vector<T> shift_down(vector<T> B, int root, int end) {
  int cur = root;
  int max_child;
  while (end >= cur * 2) {
    if (cur * 2 == end || B[cur * 2] > B[cur * 2 + 1]) max_child = cur * 2;
    else max_child = cur * 2 + 1;
    if (B[max_child] > B[cur]) {
      swap(B[cur], B[max_child]);
      cur = max_child;
    } else break;
  }
  return B;
}

template <typename T> vector<T> max_heapify(vector<T> B) {
  mrepd(i, 1, B.size()/2) {
    B = shift_down(B, i, B.size());
  }
  return B;
}

template <typename T> vector<T> heap_sort(vector<T> B) {
  mrepd(i, 1, B.size()) {
    swap(B[i], B[1]);
    B = shift_down(B, 1, i - 1);
  }
  return B;
}

int main() {
  vector<int> A;
  vector<int> B;
  int N = 20;
  rep(i, N)A.push_back(i);
  random_shuffle(A.begin(), A.end());
  rep(i, N)B.push_back(A[i]);
  // --------
  B.insert(B.begin(), 0);
  B = max_heapify(B);
  B = heap_sort(B);
  B.erase(B.begin());
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
