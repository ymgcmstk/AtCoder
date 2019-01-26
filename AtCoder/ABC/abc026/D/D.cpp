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

bool check_value(float a) {
  if (abs(a - 100) < 1e-7) return true;
  else return false;
}

double get_velocity(int A, int B, int C, double t) {
  return double(A) * t + double(B) * sin(double(C) * t * M_PI);
}

int main() {
  if (check_value(101) || !check_value(100.0000001)) {
    cout << "check_value is wrong" << endl;
    return -1;
  }
  int A, B, C;
  cin >> A >> B >> C;
  double left_t = (100 - B) / A;
  double right_t = (100 + B) / A;

  if (get_velocity(A, B, C, right_t) < 100) {
    cout << "right_t is not appropriate" << endl;
    return -1;
  }

  double mid = (left_t + right_t) / 2;
  double vel = get_velocity(A, B, C, mid);
  while (!check_value(vel)) {
    if (left_t == right_t) {
      if (vel < 100) right_t += 0.5;
      else left_t -= 0.5;
    } else {
      if (vel < 100) left_t = mid;
      else right_t = mid;
    }
    mid = (left_t + right_t) / 2;
    vel = get_velocity(A, B, C, mid);
    // cout << mid << ": " << vel << endl;
    // cout << left_t << "-" << right_t << endl;
  }
  output(mid, 16);
  // cout << mid << endl;
  return 0;
}
