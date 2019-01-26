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

template <typename T> vector<T> max_heapify(vector<T> b, int N) {
  mrepd(i, 1, N+1) {
    int cur = i;
    while (2*cur <= N+1) {
      if (b[cur] > b[cur*2] && b[cur] > b[cur*2+1]) {
        break;
      }
      if (b[cur*2] < b[cur*2+1]) {
        swap(b[cur], b[cur*2+1]);
        cur = 2 * cur + 1;
      } else {
        swap(b[cur], b[cur*2]);
        cur = 2 * cur;
      }
    }
  }
  return b;
}

template <typename T> vector<T> heap_sort(vector<T> b, int N){
  b = max_heapify(b, N);
  rep(i, N) cout << b[i+1] << ' ';
  cout << endl;
  mrepd(i, 1, N+1) {
    swap(b[i], b[1]);
    int cur = 1;
    while (2*cur <= i-1) {
      if (b[cur] > b[cur*2] && b[cur] > b[cur*2+1]) {
        break;
      }
      if (cur * 2 + 1 == i) {
        if (b[cur] < b[cur*2]) {
          swap(b[cur], b[cur*2]);
        }
        break;
      } else {
        if (b[cur*2] > b[cur*2+1]) {
          swap(b[cur], b[cur*2]);
          cur = 2 * cur;
        } else {
          swap(b[cur], b[cur*2+1]);
          cur = 2 * cur + 1;
        }
      }
    }
    rep(i, N) cout << b[i+1] << ' ';
    cout << endl;
  }
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
  B.push_back(-BN);
  B = heap_sort(B, N);
  B.erase(B.end()-1);
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
