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

void print_imp() {
  cout << "Impossible" << endl;
}

bool check(LL X, LL Y, LL targ) {
  LL sec = (targ * X) / Y;
  if ((targ * X) % Y != 0) return false;
  if (targ * (targ + 1) / 2 - sec == 0) return false;
  cout << targ << ' ' << targ * (targ + 1) / 2 - sec << endl;
  return true;
}

int main() {
  LL X, Y;
  scanf("%ld/%ld", &X, &Y);
  double Z = double(X) / double(Y);
  bool flg = false;
  LL targ;
  if (2 * X % Y == 0) targ = 2 * X / Y - 1;
  else targ = 2 * X / Y;
  if (targ > 0) flg = flg | check(X, Y, targ);
  if (targ + 1 <= 2 * Z + 1) flg = flg | check(X, Y, targ + 1);
  if (targ + 2 <= 2 * Z + 1) flg = flg | check(X, Y, targ + 2);
  if (!flg) print_imp();
  return 0;
}
