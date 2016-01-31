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
  int N;
  N = input_value();
  string S;
  cin >> S;
  int P[4] = {0};
  rep(i, N) {
    // cout << S[i] << endl;
    if (S[i] == '1') P[0]++;
    if (S[i] == '2') P[1]++;
    if (S[i] == '3') P[2]++;
    if (S[i] == '4') P[3]++;
  }
  int cur_max = 0;
  int cur_min = N;
  rep(i, 4) {
    cur_max = max(P[i], cur_max);
    cur_min = min(P[i], cur_min);
  }
  cout << cur_max << ' ' << cur_min << endl;
  // source code
  return 0;
}
