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
  int N, m, x;
  cin >> N;
  vector<int> cood, h_cood;
  vector<int> cur_max, cur_min;
  int eq1 = 0;
  int gt1 = 0;
  rep(xxx, N) {
    cood = vector<int>();
    rep(i, 3) {
      cin >> x;
      cood.push_back(x);
    }
    cin >> m;
    cur_max = vector<int>();
    cur_min = vector<int>();
    rep(i, 3) cur_max.push_back(0);
    rep(i, 3) cur_min.push_back(MOD);
    rep(yyy, m) {
      h_cood = vector<int>();
      rep(i, 3) {
        cin >> x;
        h_cood.push_back(x);
        cur_max[i] = max(cur_max[i], x);
        cur_min[i] = min(cur_min[i], x);
      }
    }
    rep(i, 3) {
      if (cur_min[i] == 1) eq1++;
      else if (cur_min[i] > 1) gt1++;
      if (cood[i] - cur_max[i] == 1) eq1++;
      else if (cood[i] - cur_min[i] > 1) gt1++;
    }
  }
  eq1 %= 2;

  return 0;
}
