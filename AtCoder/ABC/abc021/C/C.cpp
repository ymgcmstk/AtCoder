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
  int N, a, b, M, tempx, tempy;
  cin >> N;
  cin >> a >> b;
  cin >> M;
  bool P[N][N];
  rep(i, N)rep(j, N)P[i][j] = false;
  rep(i, M){
    cin >> tempx >> tempy;
    P[tempx-1][tempy-1] = true;
    P[tempy-1][tempx-1] = true;
  }
  int D[N];
  rep(i, N)D[i] = 1000;
  D[b-1] = 0;
  int C[N];
  rep(i, N)C[i] = 0;
  C[a-1] = 1;
  bool flg = true;
  while (flg) {
    flg = false;
    rep(i, N) {
      repd(j, i+1, N) {
        if (!P[i][j]) continue;
        if (D[i] + 1 < D[j]) {
          D[j] = D[i] + 1;
          flg = true;
        }
        if (D[j] + 1 < D[i]) {
          D[i] = D[j] + 1;
          flg = true;
        }
      }
    }
  }
  mrep(i, D[a-1]) {
    rep(j, N) {
      if (D[j] != i + 1) continue;
      rep(k, N) {
        if (!P[j][k]) continue;
        if (D[k] != i) continue;
        C[k] += C[j] % 1000000007;
      }
    }
  }
  cout << C[b-1] % 1000000007 << endl;
  return 0;
}
