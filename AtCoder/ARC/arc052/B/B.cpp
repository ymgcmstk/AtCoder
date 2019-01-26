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

const int MAXNUM = 20002;
bool debug_mode = false;
double vol[MAXNUM];

int main() {
  int N, Q;
  cin >> N >> Q;
  int X, R, H;
  int A, B;
  fill(vol, vol+MAXNUM, 0);
  double cur_vol, L, temp_L;
  rep(i, N) {
    cin >> X >> R >> H;
    cur_vol = pow(double(R), 2) / 3 / pow(double(H), 2) * double(M_PI);
    repd(j, X+1, X+H) {
      temp_L = double(H + X - j + 1);
      L = 3 * pow(temp_L, 2) - 3 * temp_L + 1;
      vol[j] += cur_vol * L;
    }
  }
  repd(i, 1, MAXNUM) vol[i] += vol[i-1];
  rep(i, Q) {
    cin >> A >> B;
    cout << setprecision(21) << vol[B] - vol[A] << endl;
  }
  return 0;
}
