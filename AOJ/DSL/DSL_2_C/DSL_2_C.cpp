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
struct Point {
  bool use_x;
  int x, y;
  int left, right;
  Point(bool use_x, int x, int y): use_x(use_x), x(x), y(y) {
    left = -1;
    right = -1;
  }
};


int main() {
  int N;
  cin >> N;
  int x, y;
  vector<Point> V;
  int cur, bef_cur;
  bool cur_use_x, cur_use_right;
  rep(i, N) {
    cin >> x >> y;
    V.push_back(Point((i % 2 == 0), x, y));
    cur = 0;
    cur_use_x = true;
    if (i == 0) continue;
    while (cur >= 0) {
      bef_cur = cur;
      cur_use_right = false;
      if (V[cur].use_x) {
        if (V[cur].x <= x) {
          cur = V[cur].right;
          cur_use_right = true;
        } else {
          cur = V[cur].left;
        }
        cur_use_x = true;
      } else {
        if (V[cur].y <= y) {
          cur = V[cur].right;
          cur_use_right = true;
        } else {
          cur = V[cur].left;
        }
        cur_use_x = false;
      }
    }
    if (cur_use_right) {
      V[bef_cur].right = i;
    } else {
      V[bef_cur].left = i;
    }
    V[i].use_x = !cur_use_x;
    // cout << i << ' ' << (i % 2 == 0) << ' ' << cur_use_x << endl;
  }
  int Q;
  int x1, x2, y1, y2;
  cin >> Q;

  rep(i, Q) {
    cin >> x1 >> x2 >> y1 >> y2;
    priority_queue<int> Inds;
    vector<int> Inds0;
    Inds.push(0);
    while (Inds.size() > 0) {
      cur = Inds.top();
      Inds.pop();
      if (cur < 0) continue;

      if (V[cur].use_x) {
        if (V[cur].x < x1) {
          Inds.push(V[cur].right);
        } else if (V[cur].x <= x2) {
          Inds.push(V[cur].right);
          Inds.push(V[cur].left);
        } else {
          Inds.push(V[cur].left);
        }
      } else {
        if (V[cur].y < y1) {
          Inds.push(V[cur].right);
        } else if (V[cur].y <= y2) {
          Inds.push(V[cur].right);
          Inds.push(V[cur].left);
        } else {
          Inds.push(V[cur].left);
        }
      }
      if (V[cur].x >= x1 && V[cur].x <= x2 && V[cur].y >= y1 && V[cur].y <= y2) {
        Inds0.push_back(cur);
      }
    }
    sort(Inds0.begin(), Inds0.end());
    rep(j, Inds0.size()) {
      cout << Inds0[j] << endl;
    }
    cout << endl;
  }
  return 0;
}