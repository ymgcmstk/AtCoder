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
  int V, E;
  cin >> V >> E;
  int H[V][V];
  rep(i, V) fill(H[i], H[i]+V, -MOD);
  int s, t;
  rep(i, E) {
    cin >> s >> t;
    H[s][t] = 1;
  }
  rep(i, V) rep(j, V) rep(k, V) H[j][k] = max(H[j][k], H[j][i] + H[i][k]);
  /*
  rep(i, V) {
    rep(j, V) {
      cout << H[i][j] << ' ';
    }
    cout << endl;
  }
  */
  rep(i, V) {
    if (H[i][i] > 0) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
