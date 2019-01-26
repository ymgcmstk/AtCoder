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

typedef pair<int, int> pii;

int main() {
  int N, M;
  cin >> N >> M;
  int S[M], T[M];
  vector<pii> f, s;
  vector<int> fi, si;
  int left, right, s_cur, t_cur;
  rep(i, M) {
    cin >> S[i] >> T[i];
    S[i]--;
    T[i]--;
    // update f using S[i] and T[i];
    left = 0;
    right = fi.size();
    if (i == 0) {
      fi.push_back(S[i]);
      fi.push_back(T[i]);
      continue;
    }
    while (true) {
      s_cur = (left + right) / 2;
      if (left == right) break;
      else if (fi[s_cur] < S[i] && S[i] <= fi[s_cur+1]) break;
      else if (fi[s_cur+1] < S[i]) left = s_cur;
      else right = s_cur;
    }
    left = s_cur;
    right = fi.size();
    while (true) {
      t_cur = (left + right) / 2;
      if (left == right) break;
      else if (fi[t_cur] <= T[i] && T[i] <= fi[t_cur+1]) break;
      else if (fi[t_cur+1] < T[i]) left = t_cur;
      else right = t_cur;
    }
    if (s_cur == t_cur) {
      // insert S[i] and T[i] to fi[s_cur+1] and fi[s_cur+1], respectively
    } else if ((t_cur - s_cur) % 2 == 0) {
      // remove S[i] and T[i] to fi[s_cur+1] and fi[s_cur+1], respectively
      // insert S[i] and T[i] to fi[s_cur+1] and fi[s_cur+1], respectively
      // insert S[i] and T[i] to fi[s_cur+1] and fi[s_cur+1], respectively
    } else {
      // insert S[i] and T[i] to fi[s_cur] and fi[t_cur+1], respectively
    }
  }

  rep(i, M) {
    // output
  }
  return 0;
}
