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
#define rep(i,n) repd(i,0,n)
#define LL long long

using namespace std;

bool boolfunc(bool a, int b){
  if (b < 0) return false;
  else return a;
}

int input_value(){
  int a;
  cin >> a;
  return a;
}

void input_array(int * p, int a){
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
  if(precision > 0){
    cout << setprecision(precision)  << a << "\n";
  } else {
    cout << a << "\n";
  }
}

vector<int> compute_primes(int K) {
  vector<int> primes;
  int K_root = int(sqrt(K));
  repd(i, 2, K_root+1) {
    bool flg = true;
    repd(j, 2, i) {
      if (i % j == 0) {
        flg = false;
        break;
      }
    }
    if (flg) {
      primes.push_back(i);
    }
  }
  return primes;
}

int main() {
  int N, K;
  cin >> N >> K;
  LL LSM[N+1];
  vector<int> primes = compute_primes(N);
  rep(i, N+1)LSM[i] = 0;
  vector<int> k_el;
  LL fans = 0;
  // K < N
  repd(i, 1, N+1) {
    if (K % i == 0) {
      LSM[i] = K;
      fans += K;
    }
  }
  fans %= 1000000007;
  repd(i, 1, N+1) {
    if (LSM[i] == 0) {
      fans += i * K;
      LSM[i] = i * K % 1000000007;
      fans %= 1000000007;
    }
    rep(j, primes.size()) {
      int cur_index = i;
      while (true) {
        if (!(LSM[cur_index * primes[j]] == 0)) break;
        if (cur_index * primes[j] > N) break;
        LSM[cur_index * primes[j]] = LSM[cur_index] * primes[j] % 1000000007;
        cur_index *= primes[j];
        fans += LSM[cur_index];
        fans %= 1000000007;
      }
    }
  }
  cout << fans << endl;
  // source code
  return 0;
}
