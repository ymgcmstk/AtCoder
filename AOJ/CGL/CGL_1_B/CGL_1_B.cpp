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


int main() {
  double x, y;
  int N;
  Point<double> p1, p2, p12, p0, p10, norm_p12, ptemp;
  cin >> x >> y;
  p1 = Point<double>(x, y);
  cin >> x >> y;
  p2 = Point<double>(x, y);
  p12 = p2 - p1;
  norm_p12 = p12.norm_vec();
  cin >> N;
  rep(i, N) {
    cin >> x >> y;
    p0 = Point<double>(x, y);
    p10 = p0 - p1;
    ptemp = norm_p12 * p10.dot(norm_p12);
    ptemp = p10 - ptemp;
    ptemp = ptemp * 2;
    p10 = p10 - ptemp + p1;
    if (fabs(p10.x) < 1e-15) p10.x = 0;
    if (fabs(p10.y) < 1e-15) p10.y = 0;
    cout << setprecision(15) << p10.x << ' ' << p10.y << endl;
  }
  return 0;
}
