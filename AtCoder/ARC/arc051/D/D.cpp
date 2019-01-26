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
  int W, H;
  cin >> W >> H;
  vector<int> a_num(W);
  vector<int> b_num(H);
  vector<int> a_cumm(W+1);
  vector<int> b_cumm(H+1);
  rep(i, H) {
    cin >> a_num[i];
    a_cumm[i+1] = a_cumm[i] + a_num[i];
  }
  rep(i, W) {
    cin >> b_num[i];
    b_cumm[i+1] = b_cumm[i] + b_num[i];
  }
  vector<vector<LL> > max_map;
  vector<vector<LL> > min_map;
  max_map.push_back(vector<LL>(W+1, 0));
  min_map.push_back(vector<LL>(W+1, 0));
  vector<LL> cur_max, cur_min;
  LL cur_sum;
  rep(i, H) {
    cur_max = vector<LL>(W+1, 0);
    cur_min = vector<LL>(W+1, 0);
    rep(j, W) {
      cur_sum = fuck;
      cur_max[i+1] = max(cur_max[i], cur_sum);
      cur_min[i+1] = min(cur_min[i], cur_sum);
    }
    max_map.push_back(cur_max);
    min_map.push_back(cur_min);
  }

  int Q;
  cin >> Q;
  int A, B;
  rep(i, Q) {
    cin >> A >> B;
    cout << max_map[B][A] - min_map[B-1][A-1] << endl;
  }
  return 0;
}
