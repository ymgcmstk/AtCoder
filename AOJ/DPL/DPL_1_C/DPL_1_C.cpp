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

typedef pair<int, int> PII;
typedef vector<PII> VS;

int main() {
  int N, W;
  cin >> N >> W;
  int v[N], w[N];
  int T[W+1];
  fill(T, T+W+1, 0);
  rep(i, N) {
    cin >> v[i] >> w[i];
  }
  rep(i, W+1) {
    if (T[i] == 0 && i > 0) continue;
    rep(j, N) {
      if (i + w[j] > W) continue;
      T[i + w[j]] = max(T[i + w[j]], T[i] + v[j]);
    }
  }
  int cur_max = 0;
  rep(i, W+1) cur_max = max(cur_max, T[i]);
  cout << cur_max << endl;
  return 0;
}
