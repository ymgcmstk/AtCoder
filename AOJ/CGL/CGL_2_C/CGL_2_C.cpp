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

template <typename T> class Point {
public:
  double EPS;
  T x, y;
  Point() {x = 0;y = 0;EPS = 1e-10;}
  Point(T x, T y): x(x), y(y) {EPS = 1e-10;}
  Point<T> operator + (Point &p) {return Point(this->x + p.x, this->y + p.y);}
  Point<T> operator - (Point &p) {return Point(this->x - p.x, this->y - p.y);}
  Point<T> operator * (T c) {return Point(this->x * c, this->y * c);}
  Point<T> operator / (T c) {return Point(this->x / c, this->y / c);}
  T norm() {return this->x * this->x + this->y * this->y;}
  T abs() {return sqrt(this->norm());}
  Point<T> norm_vec () {T len = this->abs(); return Point(this->x / len, this->y / len);}
  bool operator == (Point &p) {return (fabs(this->x - p.x) < this->EPS) && (fabs(this->y - p.y) < this->EPS);}
  T dot(Point &p) {return this->x * p.x + this->y * p.y;}
  T cross(Point &p) {return this->x * p.y - this->y * p.x;}
  void show() {cout << "(x, y): (" << this-x << ", " << this-y << ")" << endl;}
};

template <typename T>
class Line {
public:
  Point<T> p1;
  Point<T> p2;
  Line() {};
  Line(Point<T> p_1, Point<T> p_2) {p1 = p_1;p2 = p_2;}
  bool isSeparate(Point<T> &p_1, Point<T> &p_2) {
    Point<T> p1p2 = this->p2 - this->p1;
    Point<T> p1l1 = p_1 - this->p1;
    T cross1 = p1l1.cross(p1p2);
    Point<T> p2l2 = p_2 - this->p2;
    T cross2 = p2l2.cross(p1p2);
    if (cross1 * cross2 > p1p2.EPS) return false;
    if (cross1 * cross2 < -p1p2.EPS) return true;
    T temp_dot;
    char temp_flg1 = 0;
    char temp_flg2 = 0;
    if (fabs(cross1) < p1p2.EPS) {
      temp_dot = p1l1.dot(p1p2);
      if (temp_dot < -p1p2.EPS) temp_flg1 = 1;
      else if (temp_dot > p1p2.norm()) temp_flg1 = 2;
      else return true;
    }
    if (fabs(cross2) < p1p2.EPS) {
      temp_dot = -p2l2.dot(p1p2);
      if (temp_dot < -p1p2.EPS) temp_flg2 = 1;
      else if (temp_dot > p1p2.norm()) temp_flg2 = 2;
      else return true;
    }
    if ((temp_flg1 & temp_flg2) > 0) return true;
    else return false;
  }
  bool isIntersection(Line &l) {
    if (this->isSeparate(l.p1, l.p2) && l.isSeparate(this->p1, this->p2)) return true;
    else return false;
  }
  Point<T> crossPoint(Line &l) {
    Point<T> base, hypo1, hypo2;
    base  = this->p2 - this->p1;
    hypo1 = l.p1 - this->p1;
    hypo2 = l.p2 - this->p1;
    T t, d1, d2;
    d1 = fabs(base.cross(hypo1));
    d2 = fabs(base.cross(hypo2));
    t = d1 / (d1 + d2);
    base = ((l.p2 - l.p1) * t);
    base = base + l.p1;
    return base;
  }
};

int main() {
  int N;
  cin >> N;
  Point<double> p0, p1, p2, p3;
  rep(i, N) {
    cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    Line<double> l1 = Line<double>(p0, p1);
    Line<double> l2 = Line<double>(p2, p3);
    p0 = l1.crossPoint(l2);
    cout << setprecision(15) << p0.x << ' ' << p0.y << endl;
  }
  return 0;
}
