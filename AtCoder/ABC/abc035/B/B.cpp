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

char lrud[] = {'L', 'R', 'U', 'D', '?'};
char x[] = {-1, 1, 0, 0, 0};
char y[] = {0, 0, 1, -1, 0};

int main() {
  string S;
  int T;
  cin >> S;
  cin >> T;
  LL cur_x = 0;
  LL cur_y = 0;
  LL q_num = 0;
  for (int i = 0; i < S.length(); i++) {
    for (int j = 0; j < 5; j++) {
      if (S[i] == lrud[j]) {
        cur_x += x[j];
        cur_y += y[j];
        if (j == 4) q_num++;
      }
    }
  }
  if (T == 1) cout << abs(cur_x) + abs(cur_y) + q_num << endl;
  if (T == 2) {
    LL temp = abs(cur_x) + abs(cur_y) - q_num;
    if (temp > 0) {
      cout << abs(cur_x) + abs(cur_y) - q_num << endl;
      return 0;
    }
    if (abs(temp) % 2 == 0) cout << 0 << endl;
    else cout << 1 << endl;
  }
  return 0;
}
