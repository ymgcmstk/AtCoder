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

bool furui(int num, vector<int> primes) {
  int cur_ind = 0;
  int targ_max = floor(sqrt(num));
  while (primes.size() > cur_ind && targ_max >= primes[cur_ind]) {
    if (num % primes[cur_ind] == 0) return false;
    cur_ind++;
  }
  return true;
}

int main() {
  int N, max_num;
  max_num = -1;
  cin >> N;
  vector<int> cands(N);
  rep(i, N) {
    cin >> cands[i];
    max_num = max(max_num, cands[i]);
  }
  int sqrt_max = floor(sqrt(max_num));
  vector<bool> flg(sqrt_max + 1);
  fill(flg.begin(), flg.end(), true);
  flg[0] = false;
  flg[1] = false;
  int cur_num;
  vector<int> primes;
  repd(i, 2, floor(sqrt(sqrt_max)) + 1) {
    if (!flg[i]) continue;
    primes.push_back(i);
    cur_num = i * 2;
    while (sqrt_max >= cur_num) {
      flg[cur_num] = false;
      cur_num += i;
    }
  }
  repd(i, floor(sqrt(sqrt_max)) + 1, sqrt_max + 1) {
    if (!flg[i]) continue;
    primes.push_back(i);
  }
  int ans = 0;
  rep(i, N) if (furui(cands[i], primes)) ans += 1;
  cout << ans << endl;
  return 0;
}
