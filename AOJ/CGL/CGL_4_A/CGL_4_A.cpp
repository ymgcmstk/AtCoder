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

class Point {
public:
  int x, y;
  Point() {}
  Point(int input_x, int input_y) {
    this->x = input_x;
    this->y = input_y;
  }
  bool operator > (const Point &P) const {
    if (P.y < this->y) return true;
    else if (P.y == this->y && P.x < this->x) return true;
    else return false;
  }
  bool operator < (const Point &P) const {
    if (P.y > this->y) return true;
    else if (P.y == this->y && P.x > this->x) return true;
    else return false;
  }
};

bool is_center_left(Point top, Point center, Point bottom) {
  Point b2t = Point(top.x - bottom.x, top.y - bottom.y);
  Point b2c = Point(center.x - bottom.x, center.y - bottom.y);
  if (b2t.x * b2c.y - b2c.x * b2t.y < 0) return true;
  return false;
}

int main() {
  int N;
  cin >> N;
  vector<Point> vp;
  stack<Point> minus_side;
  stack<Point> plus_side;
  int x, y;
  bool prev2_flg;
  rep(i, N) {
    cin >> x >> y;
    vp.push_back(Point(x, y));
  }
  sort(vp.begin(), vp.end());

  plus_side.push(vp[N-1]);
  plus_side.push(vp[N-2]);
  mrep(i, N-2) {
    Point prev = plus_side.top();
    plus_side.pop();
    Point prev2 = plus_side.top();
    plus_side.pop();
    prev2_flg = true;
    while (is_center_left(vp[i], prev, prev2)) {
      prev = prev2;
      if (plus_side.empty()) {
        prev2_flg = false;
        break;
      }
      prev2 = plus_side.top();
      plus_side.pop();
    }
    if (prev2_flg) plus_side.push(prev2);
    plus_side.push(prev);
    plus_side.push(vp[i]);
  }

  minus_side.push(vp[0]);
  minus_side.push(vp[1]);
  repd(i, 2, N) {
    Point prev = minus_side.top();
    minus_side.pop();
    Point prev2 = minus_side.top();
    minus_side.pop();
    prev2_flg = true;
    while (is_center_left(vp[i], prev, prev2)) {
      prev = prev2;
      if (minus_side.empty()) {
        prev2_flg = false;
        break;
      }
      prev2 = minus_side.top();
      minus_side.pop();
    }
    if (prev2_flg) minus_side.push(prev2);
    minus_side.push(prev);
    minus_side.push(vp[i]);
  }

  cout << plus_side.size() + minus_side.size() - 2 << endl;

  while (!plus_side.empty()) {
    Point prev = plus_side.top();
    plus_side.pop();
    cout << prev.x << ' ' << prev.y << endl;
  }

  minus_side.pop();
  while (true) {
    Point prev = minus_side.top();
    minus_side.pop();
    if (minus_side.empty()) break;
    cout << prev.x << ' ' << prev.y << endl;
  }

  return 0;
}
