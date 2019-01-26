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

int main() {
  int H, W;
  cin >> H >> W;
  int max_num = 0;
  int N[H][W];
  rep(i, H) fill(N[i], N[i] + W, 0);
  rep(i, H) rep(j, W) {
    cin >> N[i][j];
    if (N[i][j] == 0) {
      N[i][j] = 1;
      max_num = 1;
    } else N[i][j] = 0;
  }

  /*
  rep(i, H) {
    rep(j, W) {
      cout << M[i][j] << ' ';
    }
    cout << endl;
  }
  */

  repd(i, 1, H) {
    repd(j, 1, W) {
      if (N[i][j]) {
        N[i][j] = min(N[i-1][j], min(N[i][j-1], N[i-1][j-1])) + 1;
        max_num = max(max_num, N[i][j]);
      }
    }
  }
  cout << max_num * max_num << endl;

  /*
  rep(i, H) {
    rep(j, W) {
      cout << N[i][j] << ' ';
    }
    cout << endl;
  }
  */

  return 0;
}
