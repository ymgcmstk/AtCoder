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
  float A1, A2, B1, B2;
  int N;
  cin >> A1 >> A2 >> B1 >> B2;
  cin >> N;
  int temp = 0;
  float X[N], Y[N];
  rep(i, N) {
    cin >> X[i] >> Y[i];
  }
  float x1, x2, y1, y2;
  rep(i, N) {
    x1 = X[i];
    y1 = Y[i];
    if (i == 0) {
      x2 = X[N-1];
      y2 = Y[N-1];
    } else {
      x2 = X[i-1];
      y2 = Y[i-1];
    }
    if (((x1 - x2) * (A2 - y1) + (y1 - y2) * (x1 - A1)) * ((x1 - x2) * (B2 - y1) + (y1 - y2) * (x1 - B1)) > 0) continue;
    if (((A1 - B1) * (y1 - A2) + (A2 - B2) * (A1 - x1)) * ((A1 - B1) * (y2 - A2) + (A2 - B2) * (A1 - x2)) > 0) continue;
    temp += 1;
  }
  cout << (temp / 2 + 1) << endl;
  return 0;
}
