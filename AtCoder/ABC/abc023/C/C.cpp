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
  int W, H, K;
  cin >> W >> H >> K;
  vector<int> w(W), h(H);
  fill(w.begin(), w.end(), 0);
  fill(h.begin(), h.end(), 0);
  int N, temp;
  LL ans = 0;
  cin >> N;
  if (N < K) {
    cout << 0 << endl;
    return 0;
  }
  int w_max = 0;
  int h_max = 0;

  int w_p[N];
  int h_p[N];
  rep(i, N) {
    cin >> w_p[i];
    w_p[i]--;
    temp = w_p[i];
    w[temp]++;
    w_max = max(w_max, w[temp]);
    cin >> h_p[i];
    h_p[i]--;
    temp = h_p[i];
    h[temp]++;
    h_max = max(h_max, h[temp]);
  }
  int w_num[max(K, w_max)+1];
  int h_num[max(K, h_max)+1];
  fill(w_num, w_num+max(K, w_max)+1, 0);
  fill(h_num, h_num+max(K, h_max)+1, 0);
  rep(i, w.size()) w_num[w[i]]++;
  rep(i, h.size()) h_num[h[i]]++;
  rep(i, K+1) ans += w_num[i] * h_num[K-i];
  if (debug_mode) {
    cout << 'w' << endl;
    rep(i, K+1) cout << w_num[i] << ' ';
    cout << endl;
    cout << 'h' << endl;
    rep(i, K+1) cout << h_num[i] << ' ';
    cout << endl;
  }
  rep(i, N) {
    if ((w[w_p[i]] + h[h_p[i]]) == K) ans--;
    else if ((w[w_p[i]] + h[h_p[i]]) == K+1) ans++;
  }
  cout << ans << endl;
  return 0;
}
