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
  int K;
  cin >> K;

  vector<double> list(K);
  vector<double> prob(K);
  double sum = 0;
  rep(i, K) {
    cin >> list[i];
    sum += list[i];
  }
  rep(i, K) prob[i] = list[i] / sum;

  int list_size = int(pow(2, K));
  vector<double> prev_step(list_size, 0);
  vector<double> cur_step;
  prev_step[0] = 1;
  double ans = 0;
  repd(i, 1, 3000) {
    cur_step = vector<double>(list_size, 0);
    rep(j, list_size-1) {
      rep(k, K) {
        cur_step[j | 1 << k] += prev_step[j] * prob[k];
      }
    }
    ans += i * cur_step[list_size-1];
    prev_step = cur_step;
  }
  cout << setprecision(15) << ans << endl;

  return 0;
}
