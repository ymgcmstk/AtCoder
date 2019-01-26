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

template <typename T> vector<T> merge(vector<T> b, int left, int right) {
  int len = right - left;
  if (len < 2) return b;
  int mid = (left + right) / 2;
  b = merge(b, left, mid);
  b = merge(b, mid, right);
  vector<T> temp_vec;
  repd(i, left, mid) temp_vec.push_back(b[i]);
  temp_vec.push_back(BN);
  repd(i, mid, right) temp_vec.push_back(b[i]);
  temp_vec.push_back(BN);
  int curl, curr;
  curl = 0;
  curr = (mid-left) + 1;
  rep(i, len) {
    if (temp_vec[curl] < temp_vec[curr]) {
      b[i + left] = temp_vec[curl];
      curl++;
    } else {
      b[i + left] = temp_vec[curr];
      curr++;
    }
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

  B = merge(B, 0, N);

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
