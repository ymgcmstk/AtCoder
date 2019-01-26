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
#define rep(i,n) repd(i,0,n)
#define LL long long

using namespace std;

bool boolfunc(bool a, int b){
  if (b < 0) return false;
  else return a;
}

int input_value(){
  int a;
  cin >> a;
  return a;
}

void input_array(int * p, int a){
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
  if(precision > 0){
    cout << setprecision(precision)  << a << "\n";
  } else {
    cout << a << "\n";
  }
}

int main() {
  int W;
  int N, K;
  cin >> W;
  cin >> N >> K;
  int A[N], B[N];
  int score[W+1][N+1][K+1];
  rep(i, N) {
    cin >> A[i] >> B[i];
  }
  int cur_max = 0;
  rep(i, W + 1) {
    rep(j, K + 1) {
      rep(k, N + 1) {
        score[i][k][j] = 0;
      }
    }
  }
  rep(j, N) {
    rep(i, W) {
      rep(k, min(j+1, K)) {
        int next_ind = A[j] + i;
        if (j > 0) score[i][j][k] = max(score[i][j-1][k], score[i][j][k]);
        if (next_ind <= W && j == 0) {
          score[next_ind][j][k+1] = B[j];
        } else if (next_ind <= W) {
          score[next_ind][j][k+1] = max(score[next_ind][j-1][k+1], score[i][j-1][k] + B[j]);
        }
      }
    }
  }
  rep(i, W + 1) {
    rep(j, K + 1) {
      rep(k, N + 1) {
        cur_max = max(score[i][k][j], cur_max);
      }
    }
  }
  cout << cur_max << endl;
  return 0;
}
