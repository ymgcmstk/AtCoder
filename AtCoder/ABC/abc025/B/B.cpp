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
  int N, A, B, d;
  string Dir;
  int x = 0;
  cin >> N >> A >> B;
  rep(i, N) {
    cin >> Dir >> d;
    if (Dir == "East") {
      if (d < A) x += A;
      else if (d < B) x += d;
      else x += B;
    } else {
      if (d < A) x -= A;
      else if (d < B) x -= d;
      else x -= B;
    }
  }
  if (x == 0) cout << 0 << endl;
  else if (x > 0) cout << "East " << x << endl;
  else cout << "West " << -x << endl;
  return 0;
}
