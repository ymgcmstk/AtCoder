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
#define MOD 1000000007
using namespace std;

template <typename T>
void show_array(T arr[]) {
  rep(i, sizeof(*arr)/sizeof(arr[0])) cout << arr[i] << ' ';
  cout << endl;
}


template <typename T>
void show_vec(vector<T> vec) {
  rep(i, vec.size()) cout << vec[i] << ' ';
  cout << endl;
}

bool debug_mode = false;

int main() {
  int N;
  string A, B;
  cin >> N;
  rep(i, N) {
    cin >> A >> B;
    vector<vector<int> > D;
    rep(j, A.size()+1) D.push_back(vector<int>(B.size()+1, 0));
    rep(a, A.size()) {
      rep(b, B.size()) {
        if (A[a+1] == B[b+1]) {
          D[a+1][b+1] = max(max(D[a][b+1], D[a+1][b]), D[a][b] + 1);
        } else {
          D[a+1][b+1] = max(D[a][b+1], D[a+1][b]);
        }
      }
    }
    cout << D[A.size()][B.size()] << endl;
  }
  return 0;
}
