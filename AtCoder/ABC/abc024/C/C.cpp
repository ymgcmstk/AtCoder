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

struct People {
  int left, right, goal, ans;
  People (int left, int right, int goal) : left(left), right(right), goal(goal) {
    ans = -1;
  }
};

int main() {
  int N, D, K;
  cin >> N >> D >> K;
  int L[D], R[D];
  int S[K], T[K];
  int SL[K], SR[K];
  rep(i, D) cin >> L[i] >> R[i];

  vector<People> Ps;

  int s, t;

  rep(i, K) {
    cin >> s >> t;
    Ps.push_back(People(s, s, t));
  }
  bool flg;
  rep(i, D + 1) {
    flg = true;
    mrep(j, Ps.size()) {
      if (Ps[j].ans >= 0) continue;
      flg = false;
      if (Ps[j].left <= Ps[j].goal && Ps[j].right >= Ps[j].goal) Ps[j].ans = i;
      if (Ps[j].left <= R[i] && Ps[j].right >= L[i]) {
        Ps[j].left = min(Ps[j].left, L[i]);
        Ps[j].right = max(Ps[j].right, R[i]);
      }
    }
    if (flg) break;
  }
  rep(i, Ps.size()) cout << Ps[i].ans << endl;

  return 0;
}
