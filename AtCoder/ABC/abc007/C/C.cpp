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

// bool debug_mode = true;
bool debug_mode = false;

typedef pair<int, int> pii;

int main() {
  int R, C;
  int sy, sx;
  int gy, gx;
  cin >> R >> C;
  cin >> sy >> sx;
  cin >> gy >> gx;
  bool M[R+2][C+2];
  int DIST[R+2][C+2];
  /*
  sx += 1;
  sy += 1;
  gx += 1;
  gy += 1;
  */
  string temp;

  rep(j, C+2){
    M[0][j]   = false;
    M[R+1][j] = false;
  }
  repd(i, 1, R+1) {
    cin >> temp;
    M[i][0]   = false;
    M[i][C+1] = false;
    if (temp.length() != C)  cout << "something wrong" << endl;
    repd(j, 1, C+1) {
      if (temp[j-1] == '#') M[i][j] = false;
      else M[i][j] = true;
    }
  }
  rep(i, R+2) fill(DIST[i], DIST[i] + C + 2, MOD);
  DIST[sy][sx] = 0;

  // priority_queue<pii, vector<pii>, greater<pii> > pq;
  queue<pii> q;
  C += 2;
  if (M[sy-1][sx]) {
    q.push(make_pair(1, (sy-1) * C + sx));
  }
  if (M[sy+1][sx]) {
    q.push(make_pair(1, (sy+1) * C + sx));
  }
  if (M[sy][sx-1]) {
    q.push(make_pair(1, sy * C + sx - 1));
  }
  if (M[sy][sx+1]) {
    q.push(make_pair(1, sy * C + sx + 1));
  }

  while (DIST[gy][gx] == MOD && q.size() > 0) {
    pii temp_pii = q.front();
    q.pop();
    sx = temp_pii.second % C;
    sy = temp_pii.second / C;
    if (DIST[sy][sx] <= temp_pii.first) continue;
    DIST[sy][sx] = temp_pii.first;
    if (M[sy-1][sx]) {
      q.push(make_pair(DIST[sy][sx] + 1, (sy-1) * C + sx));
    }
    if (M[sy+1][sx]) {
      q.push(make_pair(DIST[sy][sx] + 1, (sy+1) * C + sx));
    }
    if (M[sy][sx-1]) {
      q.push(make_pair(DIST[sy][sx] + 1, sy * C + sx - 1));
    }
    if (M[sy][sx+1]) {
      q.push(make_pair(DIST[sy][sx] + 1, sy * C + sx + 1));
    }
  }
  if (debug_mode) {
    rep(i, R+2) {
      rep(j, C+2) {
        if (DIST[i][j] == MOD) cout << 'n' << ' ';
        else cout << DIST[i][j] << ' ';
      }
      cout << endl;
    }
  }
  cout << DIST[gy][gx] << endl;
  return 0;
}
