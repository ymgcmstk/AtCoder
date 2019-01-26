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
#define MOD 2147483647
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
  int N, Q;
  cin >> N >> Q;
  int x, y, c;
  int S[N+1];
  fill(S, S+N+1, 0);
  int V[N+1];
  fill(V, V+N+1, 0);
  rep(i, Q) {
    cin >> c >> x >> y;
    if (c == 0) {
      repd(j, x, N+1) {
        S[j] += y;
      }
    } else {
      if (x == 0) cout << S[y] << endl;
      else cout << S[y] - S[x-1] << endl;
    }
  }
  return 0;
}
