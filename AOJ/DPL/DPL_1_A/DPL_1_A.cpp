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
  int N, M;
  cin >> N >> M;
  int C[M];
  rep(i, M) cin >> C[i];
  int P[N+1];
  fill(P, P+N+1, -1);
  P[0] = 0;
  rep(i, N) {
    if (P[i] < 0) continue;
    rep(j, M) {
      if (i + C[j] > N) continue;
      if (P[i + C[j]] < 0) P[i + C[j]] = P[i] + 1;
      else P[i + C[j]] = min(P[i + C[j]], P[i] + 1);
    }
  }
  cout << P[N] << endl;
  return 0;
}
