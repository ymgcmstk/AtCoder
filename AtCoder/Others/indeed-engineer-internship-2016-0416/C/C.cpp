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

int row_num[6] = {0, 0, 0, 0, 0, 0};
int col_num[6] = {0, 0, 0, 0, 0, 0};
vector<vector<bool> > dotmap;

LL count_num(int start_num, bool first=false) {
  LL ans = 0;
  bool flg = true;
  if (start_num / 6 > 0) if (row_num[start_num / 6 - 1] < 3) return ans;
  rep(i, 6) {
    if (row_num[i] < 3 || col_num[i] < 3) {
      flg = false;
      break;
    }
  }
  if (flg) {
    ans++;
    return ans;
  }
  if (start_num >= 36) return ans;

  int start_i, start_j;
  repd(i, start_num, 36) {
    if (debug_mode) if (first) cout << i << endl;
    start_i = i / 6;
    start_j = i % 6;
    if (dotmap[start_i][start_j]) continue;
    if (row_num[start_i] == 3 || col_num[start_j] == 3) continue;
    dotmap[start_i][start_j] = true;
    row_num[start_i]++;
    col_num[start_j]++;
    ans += count_num(i+1);
    dotmap[start_i][start_j] = false;
    row_num[start_i]--;
    col_num[start_j]--;
  }
  return ans;
}

int main() {
  string cur_str;
  int N;
  rep(i, 6) {
    cin >> cur_str;
    vector<bool> vb;
    rep(j, 6) {
      if (cur_str[j] == '.') vb.push_back(false);
      else {
        row_num[i] += 1;
        col_num[j] += 1;
        vb.push_back(true);
      }
    }
    dotmap.push_back(vb);
  }
  rep(i, 6) {
    if (row_num[i] > 3 || col_num[i] > 3) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << count_num(0, true) << endl;
  return 0;
}
