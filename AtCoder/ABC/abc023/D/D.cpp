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

typedef vector<pair<int, int> > vpii;

int main() {
  int N;
  cin >> N;
  int H[N];
  int S[N];
  vpii sv;
  int cur_end = N-1;
  rep(i, N) {
    cin >> H[i] >> S[i];
    sv.push_back(make_pair(H[i] + S[i] * (N-1), S[i]));
  }
  int ans = -MOD;
  int i = 0;
  while (i < N) {
    sort(sv.begin()+i, sv.end());
    int cur_i = i;
    if (ans >= sv[cur_i].first) {
      while (ans >= sv[i].first - (i - cur_i) * sv[i].second) {
        i++;
        if (i == N) {
          cout << ans << endl;
          return 0;
        }
      }
    } else {
      ans = sv[i].first;
      i++;
    }
    repd(j, i, N) {
      sv[j].first -= sv[j].second * (i - cur_i);
    }
  }
  cout << ans << endl;

  return 0;
}
