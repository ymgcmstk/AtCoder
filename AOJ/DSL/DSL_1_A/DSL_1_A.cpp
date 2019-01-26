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

struct Edge {
  int to, len;
  Edge(int to): to(to) {
    len = 1;
  }
};

typedef vector<Edge> Edges;

int main() {
  int N, Q;
  cin >> N >> Q;
  // source code
  Edges E;
  rep(i, N) E.push_back(Edge(i));
  int c, x, y;
  rep(i, Q) {
    cin >> c >> x >> y;
    if (c == 0) {
      while (E[x].to != x) x = E[x].to;
      while (E[y].to != y) y = E[y].to;
      if (E[x].len > E[y].len) {
        E[y].to = x;
      } else if (E[x].len < E[y].len) {
        E[x].to = y;
      } else {
        E[x].to = y;
        E[y].len++;
      }
    } else if (c == 1) {
      while (E[x].to != x) x = E[x].to;
      while (E[y].to != y) y = E[y].to;
      if (x == y) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
  return 0;
}
