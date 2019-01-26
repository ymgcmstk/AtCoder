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

template <typename T> void input_array(T * p){
  int a = sizeof(p) / sizeof(p[0]);
  rep(i, a){
    cin >> p[i];
  }
}

void input_vector(vector<int> * p, int a){
  rep(i, a){
    int input;
    cin >> input;
    p -> push_back(input);
  }
}

template <typename T>
void output(T a, int precision) {
  if (precision > 0) {
    cout << setprecision(precision)  << a << "\n";
  } else {
    cout << a << "\n";
  }
}

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

int bit_count(int num) {
  int ans = 0;
  int temp = 0;
  while ((1 << temp) <= num) {
    if (((1 << temp) & num) > 0) ans += 1;
    temp++;
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  bool ans[(1 << N)];
  fill(ans, ans + (1 << N), false);
  // rep(i, N) ans[1 << i] = true;
  int x, y;
  int max_num = 1;
  rep(i, M) {
    cin >> x >> y;
    x--;
    y--;
    ans[(1 << x) + (1 << y)] = true;
    max_num = 2;
  }
  rep(i, 1 << N) {
    if (bit_count(i) < 3) continue;
    if (debug_mode) cout << i << ' ' << bit_count(i) << endl;
    ans[i] = true;
    rep(j, N) {
      if (debug_mode) cout << i << ' ' << j << ' ' << (i & ~(1 << j)) << " ans: " << ans[(i & ~(1 << j))] << ' ' << (1 << N)<< endl;
      if ((!ans[(i & ~(1 << j))]) && i != (i & ~(1 << j))) {
        ans[i] = false;
        break;
      } else if (i < (1 << j)) {
        break;
      }
    }
    if (ans[i]) max_num = max(max_num, bit_count(i));
  }
  cout << max_num << endl;
  return 0;
}
