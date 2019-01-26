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
  int U[H][W];
  int temp;
  rep(i, H) rep(j, W) {
    scanf("%d", &temp);
    if (temp == 0) {
      if (i >= 1) {
        U[i][j] = U[i-1][j] + 1;
      } else {
        U[i][j] = 1;
      }
    } else {
      U[i][j] = 0;
    }
  }

  /*
  rep(i, H) {
    rep(j, W) {
      cout << M[i][j] << ' ';
    }
    cout << endl;
  }
  */

  stack<pair<int, int> > sv;
  pair<int, int> cur_pii;
  int cur_left;
  int cur_max;
  rep(i, H) {
    rep(j, W) {
      cur_left = j;
      while (!sv.empty() && sv.top().first > U[i][j]) {
        cur_pii = sv.top();
        max_num = max(max_num, cur_pii.first * (j - cur_pii.second));
        cur_left = cur_pii.second;
        sv.pop();
      }
      sv.push(make_pair(U[i][j], cur_left));
    }
    while (!sv.empty()) {
      cur_pii = sv.top();
      sv.pop();
      max_num = max(max_num, cur_pii.first * (W - cur_pii.second));
    }
  }
  cout << max_num << endl;

  /*
  rep(i, H) {
    rep(j, W) {
      cout << U[i][j] << ' ';
    }
    cout << endl;
  }
  */
  return 0;
}
