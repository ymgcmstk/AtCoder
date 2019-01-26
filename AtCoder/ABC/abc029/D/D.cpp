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

bool debug_mode = false;

int main() {
  int all = 0;
  int N;
  cin >> N;
  int cur_a = 1;
  int a, b;
  if (debug_mode) cout << N << endl;
  while (cur_a <= N) {
    a = min(max(N % (10 * cur_a) - cur_a, -1) + 1, cur_a);
    b = (N / (cur_a * 10)) * cur_a;
    all += a;
    all += b;
    if (debug_mode) {
      cout << "cur_a: " << cur_a << ", min(N % cur_a + 1, cur_a): " << a << ", N / (cur_a * 10) * cur_a: " << b <<endl;
    }
    cur_a *= 10;
  }
  cout << all << endl;
  return 0;
}
