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

template <typename T> void input_array(T * p){
  int a = sizeof(p) / sizeof(p[0]);
  rep(i, a){
    cin >> p[i];
  }
}

void input_vector(vector<int> * p, int a){
  rep(i, a){
    int input;
    cin >> input;
    p -> push_back(input);
  }
}

template <typename T>
void output(T a, int precision) {
  if (precision > 0) {
    cout << setprecision(precision)  << a << "\n";
  } else {
    cout << a << "\n";
  }
}

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
  int R, C, K;
  cin >> R >> C >> K;
  bool A[R][C];
  rep(i, R) fill(A[i], A[i]+C, true);
  string temp_str;
  rep(i, R) {
    cin >> temp_str;
    rep(j, temp_str.length()) {
      if (temp_str[j] == 'x') {
        repd(k, - K + 1, K) {
          if (i + k < 0 || i + k > R - K + 1) continue;
          repd(l, - K + 1 + int(abs(k)),  K - int(abs(k))) {
            if (j + l < 0 || j + l > C - K + 1) continue;
            A[i+k][j+l] = false;
          }
        }
      }
    }
  }
  if (debug_mode) {
    repd(i, K-1, R-K+1) {
      repd(j, K-1, C-K+1) {
        if (A[i][j]) cout << 'o';
        else cout << 'x';
      }
      cout << endl;
    }
  }
  if (debug_mode) {
    rep(i, R) {
      rep(j, C) {
        if (A[i][j]) cout << 'o';
        else cout << 'x';
      }
      cout << endl;
    }
  }
  int ans = 0;
  repd(i, K-1, R-K+1) repd(j, K-1, C-K+1) if (A[i][j]) ans++;
  cout << ans << endl;
  return 0;
}
