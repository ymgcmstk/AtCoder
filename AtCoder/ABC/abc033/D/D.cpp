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
#define LL int
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

bool debug_mode = true;

const char AC = 0;
const char RI = 1;
const char OB = 2;

char check_triangle(LL a, LL b, LL c) {
  LL cur_max = a;
  if (cur_max <= b) cur_max = b;
  if (cur_max <= c) cur_max = c;
  // cout << a << ' ' << b << ' ' << c << ' ' << cur_max << endl;
  if ((a + b + c) < 2 * cur_max) return OB;
  else if ((a + b + c) == 2 * cur_max) return RI;
  else return AC;
}

int main() {
  int N;
  cin >> N;
  vector<Point<LL> > vP;
  LL x, y;
  LL dist[N][N];

  rep(i, N) {
    cin >> x >> y;
    vP.push_back(Point<LL>(x, y));
  }
  rep(i, N-1) {
    dist[i][i] = 0;
    repd(j, i+1, N) {
      Point<LL> temp_P = vP[i] - vP[j];
      dist[i][j] = temp_P.norm();
      dist[j][i] = dist[i][j];
      // cout << i << ' ' << j << ' ' << dist[i][j] << endl;
    }
  }
  int right  = 0;
  int acute  = 0;
  int obtuse = 0;
  rep(i, N-2) {
    repd(j, i+1, N-1) {
      repd(k, j+1, N) {
        char temp = check_triangle(dist[i][j], dist[j][k], dist[k][i]);
        if (temp == OB) obtuse++;
        else if (temp == AC) acute++;
        else right++;
      }
    }
  }
  if (obtuse + acute + right != N * (N-1) * (N-2) / 6) cout << "ERROR" << endl;
  cout << acute << ' ' << right << ' ' << obtuse << endl;
  return 0;
}
