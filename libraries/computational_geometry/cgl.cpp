#include <vector>
#include <cmath>
using namespace std;

template <typename T> class Point {
public:
  double EPS;
  T x, y;
  Point() {x = 0;y = 0;EPS = 1e-10;}
  Point(T x, T y): x(x), y(y) {EPS = 1e-10;}
  Point<T> operator + (Point &p) {return Point(this->x + p.x, this->y + p.y);}
  Point<T> operator - (Point &p) {return Point(this->x - p.x, this->y - p.y);}
  Point<T> operator * (T c) {return Point(this->x * c, this->y * c);}
  T norm() {return this->x * this->x + this->y * this->y;}
  T abs() {return sqrt(this->norm);}
  bool operator == (Point &p) {return (fabs(this->x - p.x) < this->EPS) && (fabs(this->y - p.y) < this->EPS);}
  T dot(Point &p) {return this->x * p.x + this->y * p.y;}
  T cross(Point &p) {return this->x * p.y - this->y * p.x;}
  void show() {cout << "(x, y): (" << this-x << ", " << this-y << ")" << endl;}
};

template <typename T> class Line {
public:
  Point<T> p1, p2;
  Line(Point<T> p_1, Point<T> p_2) {p1 = p_1;p2 = p_2;}
};

template <typename T> class Circle {
public:
  Point<T> c;
  T r;
  Circle(Point<T> c = Point<T>(), double r = 0.0): c(c), r(r) {}
};

// typedef vector<Point> Polygon;
