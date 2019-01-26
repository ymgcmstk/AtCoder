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
  int N, T;
  cin >> N >> T;
  int A[N];
  bool S[N];
  fill(S, S+N, false);
  rep(i, N) {
    cin >> A[i];
    A[i]--;
    S[i] = true;
  }
  int cur = max(max((N / T - 1), A[0]), T - 1 - A[N-1]);
  rep(i, A[0]) S[i] = true;
  // cout << "(" << cur << ")" << endl;
  while (true) {
    int cur_s = 0;
    bool flg = false;
    rep(i, N-1) {
      // if (cur - (A[i] - cur_s) < 0 && cur - 2 * (A[i] - cur_s) < 0) {
      // flg = true;
      // break;
      // }
      cur_s = min(max(A[i] + (cur - (A[i] - cur_s))/2, A[i] + (cur - 2 * (A[i] - cur_s))), A[i+1]);
    }
    if (!flg) {
      if ((T - 1 - A[N-1] > A[N-1] - cur_s && cur >= 2 * (A[N-1] - cur_s) + T - 1 - A[N-1]) || (T - 1 - A[N-1] <= A[N-1] - cur_s && cur >= A[N-1] - cur_s + 2 * (T - 1 - A[N-1]))) {
        cout << cur+1 << endl;
        return 0;
      }
    }
    cur++;
  }
  return 0;
}
