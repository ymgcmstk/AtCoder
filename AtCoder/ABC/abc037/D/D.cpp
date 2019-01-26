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

const int d_x[] = {0, 1, 0, -1};
const int d_y[] = {1, 0, -1, 0};

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

bool debug_mode = false;

int main() {
  int H, W;
  cin >> H >> W;
  int a[H][W];
  LL b[H][W];
  int temp;
  vector<pair<int, int> > temp_vec;
  rep(i, H) {
    rep(j, W) {
      cin >> temp;
      a[i][j] = temp;
      b[i][j] = 1;
      temp_vec.push_back(make_pair(-temp, i * W + j));
    }
  }
  sort(temp_vec.begin(), temp_vec.end());
  int x, y, org_x, org_y;
  rep(i, temp_vec.size()) {
    org_x = temp_vec[i].second / W;
    org_y = temp_vec[i].second % W;
    rep(j, 4) {
      x = org_x + d_x[j];
      y = org_y + d_y[j];
      if (x < 0 || x >= H || y < 0 || y >= W) continue;
      if (a[x][y] > a[org_x][org_y]) b[org_x][org_y] += b[x][y];
    }
  }
  LL sum = 0;
  rep(i, H) {
    rep(j, W) {
      sum = (sum + b[i][j]) % MOD;
    }
  }
  cout << sum << endl;
  return 0;
}
