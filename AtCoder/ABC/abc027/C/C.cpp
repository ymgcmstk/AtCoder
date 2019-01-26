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
  LL N;
  cin >> N;
  if (N == 1) {
    cout << "Aoki" << endl;
    return 0;
  }
  LL cur_num = 1;
  int cur_loop = 1;
  N = (N + 1) / 2 - 1;
  while (true) {
    cur_loop++;
    cur_num <<= 1;
    if (N >> cur_loop == 0) {
      if (cur_loop % 2 == 1) {
        if (!(cur_loop >= N)) {
          cout << "Takahashi" << endl;
        } else {
          cout << "Aoki" << endl;
        }
      } else {
        if (!(cur_loop >= N)) {
          cout << "Aoki" << endl;
        } else {
          cout << "Takahashi" << endl;
        }
      }
      break;
    }
    if (cur_loop % 2 == 1) cur_num++;
  }
  return 0;
}
