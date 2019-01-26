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

// fuck

void display(vector<bool> vb) {
  rep(i, vb.size()) {
    if (vb[i]) cout << 'o';
    else cout << 'x';
  }
  cout << endl;
}

bool check(int num, vector<bool> vb, vector<bool> cur_vb, vector<bool> start_flg) {
  bool flg = true;
  rep(i, cur_vb.size()) {
    if (!cur_vb[i]) {
      flg = false;
      break;
    }
  }
  if (flg) return true;
  if (num == 0) {
    return false;
  }
  rep(i, cur_vb.size()) {
    if (start_flg[i]) continue;
    vector<bool> next_vb(cur_vb.size(), false);
    rep(j, cur_vb.size()) next_vb[j] = cur_vb[j] | vb[(i + j) % cur_vb.size()];
    start_flg[i] = true;
    if (check(num-1, vb, next_vb, start_flg)) return true;
    start_flg[i] = false;
  }
  return false;
}

int main() {
  string str;
  if (debug_mode) {
    vector<bool> vb(4, false);
    vb[0] = true;
    vb[1] = true;
    if (check(0, vb, vector<bool>(vb.size(), true), vector<bool>(vb.size(), false))) {
      cout << "test1 passed" << endl;
    }
    if (!check(1, vb, vector<bool>(vb.size(), false), vector<bool>(vb.size(), false))) {
      cout << "test2 passed" << endl;
    }
    if (check(2, vb, vector<bool>(vb.size(), false), vector<bool>(vb.size(), false))) {
      cout << "test3 passed" << endl;
    }
  } else {
    cin >> str;
    vector<bool> vb(str.length(), false);
    int count = 0;
    rep(i, str.length()) {
      if (str[i] == 'o') {
        vb[i] = true;
        count += 1;
      }
    }
    int left = str.size() / count;
    int right = str.size();
    int mid = (left + right) / 2;
    while (mid > left) {
      if (check(mid, vb, vector<bool>(vb.size(), false), vector<bool>(vb.size(), false))) right = mid;
      else left = mid;
      mid = (left + right) / 2;
    }
    if (check(mid, vb, vector<bool>(vb.size(), false), vector<bool>(vb.size(), false))) cout << mid << endl;
    else cout << mid + 1 << endl;
  }
  return 0;
}
