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

vector<int> shift_down(vector<int> b, int root, int end) {
  int max_child;
  while (2 * root <= end-1) {
    if (2 * root == end-1) max_child = 2 * root;
    else if (b[2 * root + 1] < b[2 * root]) max_child = 2 * root;
    else max_child = 2 * root + 1;
    if (b[max_child] < b[root]) break;
    else {
      swap(b[max_child], b[root]);
      root = max_child;
    }
  }
  return b;
}

vector<int> heap_sort(vector<int> b) {
  mrepd(i, 1, b.size()) {
    swap(b[i], b[1]);
    b = shift_down(b, 1, i);
  }
  return b;
}

vector<int> make_heap(vector<int> b) {
  mrepd(i, 1, b.size()/2) b = shift_down(b, i, b.size());
  return b;
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
  B = make_heap(B);
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
