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
  int N;
  cin >> N;
  int h[N];
  int p = pow(10, 5);
  int n1[N], n2[N];
  fill(n1, n1+N, 0);
  fill(n2, n2+N, 0);
  rep(i, N) cin >> h[i];
  int cur;
  repd(i, 1, N) {
    cur = i - 1;
    while (h[cur] <= h[i] && cur >= 0) {
      n1[i] += (1 + n1[cur]);
      cur = i - 1 - n1[i];
    }
  }
  mrep(i, N-1) {
    cur = i + 1;
    while (h[cur] <= h[i] && cur <= N-1) {
      n2[i] += (1 + n2[cur]);
      cur = i + 1 + n2[i];
    }
  }
  // mrep(i, N-1) if (h[i] >= h[i+1]) n2[i] += (1 + n2[i+1]);
  rep(i, N) cout << (n1[i] + n2[i]) << endl;
  // rep(i, N) cout << h[i] << ' ' << n1[i] << ' ' << n2[i] << endl;
  return 0;
}
