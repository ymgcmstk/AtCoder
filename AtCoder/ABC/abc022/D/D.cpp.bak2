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
#define BN 1000000007
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
  cin >> N;
  float Ax[N], Ay[N];
  float Bx[N], By[N];
  float sumx, sumy;
  float vx, vy;
  float A, B;
  sumx = 0;
  sumy = 0;
  rep(i, N) {
    cin >> Ax[i] >> Ay[i];
    sumx += Ax[i];
    sumy += Ay[i];
  }
  sumx /= N;
  sumy /= N;
  A = 0;
  rep(i, N) {
    Ax[i] -= sumx;
    Ay[i] -= sumy;
    cout << sqrt(pow(Ax[i], 2) + pow(Ay[i], 2)) << endl;
    A = max(A, sqrt(pow(Ax[i], 2) + pow(Ay[i], 2)));
  }

  sumx = 0;
  sumy = 0;
  rep(i, N) {
    cin >> Bx[i] >> By[i];
    sumx += Bx[i];
    sumy += By[i];
  }
  sumx /= N;
  sumy /= N;
  B = 0;
  rep(i, N) {
    Bx[i] -= sumx;
    By[i] -= sumy;
    B = max(B, sqrt(pow(Bx[i], 2) + pow(By[i], 2)));
  }

  cout << (B/A) << endl;

  return 0;
}
