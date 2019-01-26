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
  int H, W, T, N;
  cin >> H >> W >> T;
  char M[H][W];
  int s_h;
  int s_w;
  int g_h;
  int g_w;
  string tempstr;
  rep(i, H){
    cin >> tempstr;
    rep(j, W){
      M[i][j] = tempstr[j];
      if (M[i][j] == 'S') {
        s_h = i;
        s_w = j;
      } else if (M[i][j] == 'G') {
        g_h = i;
        g_w = j;
      }
    }
  }
  N = abs(s_h - g_h) + abs(s_w - g_w);
  int cost[H][W][N];
  rep(i, H)rep(j, W)rep(k, N)cost[i][j][k] = 10000000;
  cost[s_h][s_w][0] = 0;
  int fans = 1;
  rep(i, N) {
    bool flg = true;
    while (flg) {
      flg = false;
      rep(j, H){
        rep(k, W){
          if (M[j][k] == '#') continue;
          if (j > 0) {
            if (cost[j-1][k][i] + 1 < cost[j][k][i]) {
              flg = true;
              cost[j][k][i] = cost[j-1][k][i] + 1;
            }
          }
          if (j < H-1) {
            if (cost[j+1][k][i] + 1 < cost[j][k][i]) {
              flg = true;
              cost[j][k][i] = cost[j+1][k][i] + 1;
            }
          }
          if (k > 0) {
            if (cost[j][k-1][i] + 1 < cost[j][k][i]) {
              flg = true;
              cost[j][k][i] = cost[j][k-1][i] + 1;
            }
          }
          if (k < W-1) {
            if (cost[j][k+1][i] + 1 < cost[j][k][i]) {
              flg = true;
              cost[j][k][i] = cost[j][k+1][i] + 1;
            }
          }
        }
      }
    }
    // temp
    if (cost[g_h][g_w][i] < 10000000) {
      fans = max((T - cost[g_h][g_w][i])/i, fans);
    }
    if (i == N - 1) break;
    if (cost[g_h][g_w][i] + i == N) break;
    rep(j, H){
      rep(k, W){
        if (M[j][k] == '#') {
          if (j > 0) cost[j][k][i+1] = min(cost[j - 1][k][i], cost[j][k][i+1]);
          if (j < H - 1) cost[j][k][i+1] = min(cost[j + 1][k][i], cost[j][k][i+1]);
          if (k > 0) cost[j][k][i+1] = min(cost[j][k - 1][i], cost[j][k][i+1]);
          if (k < W - 1) cost[j][k][i+1] = min(cost[j][k + 1][i], cost[j][k][i+1]);
        }
      }
    }
  }
  cout << fans << endl;
  return 0;
}
