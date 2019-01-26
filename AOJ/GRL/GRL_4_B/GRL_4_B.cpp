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
typedef vector<vector<int> > vvi;

int main() {
  int V, E;
  cin >> V >> E;
  int temps, tempt;
  int c[E];
  // vector<int> VI;
  set<int> S;
  vvi VVI;
  rep(i, E) VVI.push_back(vector<int>());
  fill(c, c+E, 0);
  rep(i, E) {
    cin >> temps >> tempt;
    c[tempt]++;
    VVI[temps].push_back(tempt);
  }
  queue<int> Q;
  int i = 0;
  while (S.size() < E) {
    if (c[i] == 0) {
      S.insert(i);
      cout << i << endl;
      rep(j, VVI[i].size()) {
        c[VVI[i][j]]--;
      }
      c[i]--;
    }
    i++;
    i %= E;
  }
  return 0;
}
