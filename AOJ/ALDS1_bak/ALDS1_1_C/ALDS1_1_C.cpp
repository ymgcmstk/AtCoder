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

bool isPrime(int num, vector<int> prime) {
  int cur = 0;
  while (num >= prime[cur] && cur < prime.size()) {
    if (num == prime[cur]) return true;
    if (num % prime[cur] == 0) return false;
    cur++;
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  int temp;
  vector<int> prime_candidates;
  int cur_max = 0;
  rep(i, N) {
    cin >> temp;
    prime_candidates.push_back(temp);
    cur_max = max(cur_max, temp);
  }
  int cur_min = floor(sqrt(cur_max));
  bool prime_flg[cur_min+1];
  fill(prime_flg, prime_flg+cur_min+1, true);
  prime_flg[0] = false;
  prime_flg[1] = false;
  vector<int> primes;
  repd(i, 2, cur_min+1) {
    if (!prime_flg[i]) continue;
    primes.push_back(i);
    int cur_ind = i * 2;
    while (cur_ind <= cur_min+1) {
      prime_flg[cur_ind] = false;
      cur_ind += i;
    }
  }
  int ans = 0;
  rep(i, N) if (isPrime(prime_candidates[i], primes)) ans++;
  cout << ans << endl;
  return 0;
}
