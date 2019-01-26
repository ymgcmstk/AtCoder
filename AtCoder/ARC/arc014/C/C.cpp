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
  int N;
  string rgbs;
  cin >> N;
  cin >> rgbs;
  bool flg = true;
  int cur_ind = 0;
  while (flg) {
    if (cur_ind < rgbs.size() - 1) {
      if (rgbs[cur_ind] == rgbs[cur_ind+1]) {
        rgbs = rgbs.substr(0, cur_ind) + rgbs.substr(cur_ind+2);
        cur_ind = 0;
        continue;
      }
      if (cur_ind < rgbs.size() - 2) {
        if (rgbs[cur_ind] == rgbs[cur_ind+2]) {
          rgbs = rgbs.substr(0, cur_ind) + rgbs.substr(cur_ind+1, 1) + rgbs.substr(cur_ind+3);
          cur_ind = 0;
          continue;
        }
      }
    } else {
      break;
    }
    cur_ind++;
  }

  cout << rgbs << endl;
  return 0;
}
