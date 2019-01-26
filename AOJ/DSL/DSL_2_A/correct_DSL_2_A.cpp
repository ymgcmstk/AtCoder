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
#define INF 2147483647
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

int rmq(int * S, int cur, int a, int b, int left, int right, int s_temp) {
  if ((left <= a && b - 1 <= right)) return S[cur];
  else if ((left > b - 1 || a > right)) return INF;
  else return min(rmq(S, 2*cur, a, (a+b)/2, left, right, s_temp), rmq(S, 2*cur+1, (a+b)/2, b, left, right, s_temp));
}

int main() {
  int N, Q;
  cin >> N >> Q;
  int depth = 0;
  while (((N - 1) >> depth) != 0) depth++;
  depth++;
  int s_temp = 1 << depth;
  int S[s_temp];
  rep(i, s_temp) S[i] = INF;
  int c, x, y;
  int cur;
  rep(i, Q) {
    cin >> c >> x >> y;
    if (c == 0) {
      cur = x + s_temp / 2;
      S[cur] = y;
      cur /= 2;
      while (cur > 0) {
        if ((S[cur] == min(S[cur*2], S[cur*2+1])) && cur != x + s_temp / 2) break;
        S[cur] = min(S[cur*2], S[cur*2+1]);
        cur /= 2;
      }
    } else {
      cout << rmq(S, 1, 0, (1 << (depth - 1)), x, y, s_temp) << endl;
    }
  }
  return 0;
}
