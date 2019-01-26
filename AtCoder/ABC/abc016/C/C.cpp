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
  int N, M;
  cin >> N >> M;
  bool R[N][N];
  rep(i, N) {
    rep(j, N) {
      R[i][j] = false;
    }
  }
  int temp1, temp2;
  rep(i, M) {
    cin >> temp1 >> temp2;
    R[temp1-1][temp2-1] = true;
    R[temp2-1][temp1-1] = true;
  }
  int cur_R[N];
  rep(i, N) {
    rep(j, N) {
      cur_R[j] = false;
    }
    rep(j, N) {
      if (R[i][j]) {
        rep(k, N) {
          if (R[j][k]) cur_R[k] = true;
        }
      }
    }
    rep(j, N) {
      if (R[i][j]) cur_R[j] = false;
      if (i == j) cur_R[j] = false;
    }
    temp1 = 0;
    rep(j, N) {
      if (cur_R[j]) temp1++;
    }
    cout << temp1 << endl;
  }
  return 0;
}
