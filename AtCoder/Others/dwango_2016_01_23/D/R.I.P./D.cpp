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

#define         repd(i,a,b)  for (int i=(a);i<(b);i++)
#define         mrepd(i,a,b) for (int i=(b-1);i >= (a);i--)
#define rep(i,n)     repd(i,0,n)
#define mrep(i,n)    mrepd(i,0,n)
#define LL           long long
#define MOD          1000000007
using namespace std;

template <typename T> void input_array(T * p){
  int a = sizeof(p) / sizeof(p[0]);
  rep(i, a){
    cin >> p[i];
  }
}

void input_vector(vector<int> * p, int a){
  rep(i, a){
    int                         input;
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

template <typename T>
void show_array(T arr[]) {
  rep(i, sizeof(*arr)/sizeof(arr[0])) cout << arr[i] << ' ';
  cout << endl;
}


template <typename T>
void show_vec(vector<T> vec) {
  rep(i, vec.size()) cout << vec[i] << ' ';
  cout << endl;
}

bool debug_mode = true;

typedef vector<vector<int> > vii;

struct Rect {
  int x_s, x_l, y_s, y_l, area;
  Rect (int x_s, int x_l, int y_s, int y_l, int area) : x_s(x_s), x_l(x_l), y_s(y_s), y_l(y_l), area(area) {}
  void disp() {
    cout << "x_s: " << x_s << ", x_l: " << x_l << ", y_s: " << y_s << ", y_l: " << y_l << ", area: " << area << endl;
  }
};

bool overwrap(Rect r1, Rect r2) {
  // if (r1.x_s > r2.x_l && r2.x_s > r1.x_l && r1.y_s > r2.y_l && r2.y_s > r1.y_l ) return true;
  if (r1.x_s < r2.x_l && r2.x_s < r1.x_l && r1.y_s < r2.y_l && r2.y_s < r1.y_l) return true;
  else return false;
}

typedef vector<pair<int, int> > vpii;

int main() {
  int H, W;
  cin >> H >> W;
  int B[H][W];
  int B_sum[H][W];
  rep(i, H) rep(j, W) cin >> B[i][j];
  int cur_sum;
  rep(i, H) {
    cur_sum = 0;
    if (i == 0) {
      rep(j, W) {
        cur_sum += B[i][j];
        B_sum[i][j] = cur_sum;
      }
    } else {
      rep(j, W) {
        cur_sum += B[i][j];
        B_sum[i][j] = B_sum[i-1][j] + cur_sum;
      }
    }
  }
  vector<Rect> vR;
  int area;
  vpii vRind;
  int cur_ind=0;
  repd(i, -1, H) {
    repd(j, -1, W) {
      repd(k, i+1, H) {
        repd(l, j+1, W) {
          area = B_sum[k][l];
          if (i > -1) area -= B_sum[i][l];
          if (j > -1) area -= B_sum[k][j];
          if (i > -1 && j > -1) area += B_sum[i][j];
          vR.push_back(Rect(j, l, i, k, area));
          vRind.push_back(make_pair(-area, cur_ind));
          cur_ind++;
        }
      }
    }
  }
  if (debug_mode) {
    rep(i, H) {
      rep(j, W) {
        cout << B_sum[i][j] << ' ';
      }
      cout << endl;
    }
  }
  sort(vRind.begin(), vRind.end());
  int cur_max = -MOD;
  int last_ind = vRind.size();
  rep(i, vRind.size()) {
    repd(j, i+1, last_ind) {
      if (!overwrap(vR[vRind[i].second], vR[vRind[j].second])) {
        cur_max = max(cur_max, -(vRind[i].first+vRind[j].first));
        last_ind = j;
        if (debug_mode) {
          vR[vRind[i].second].disp();
          vR[vRind[j].second].disp();
        }
        break;
      }
    }
    if (i-1 == last_ind) break;
  }
  cout << cur_max << endl;
  return 0;
}
