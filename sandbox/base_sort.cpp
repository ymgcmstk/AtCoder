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

int main() {
  vector<int> A;
  vector<int> B;
  int N = 20;
  rep(i, N)A.push_back(i);
  random_shuffle(A.begin(), A.end());
  rep(i, N)B.push_back(A[i]);
  // --------



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
