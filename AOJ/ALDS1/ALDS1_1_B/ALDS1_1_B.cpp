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

int GCD(int N, int M) {
  int n1 = max(N, M);
  int n2 = min(N, M);
  while (true) {
    if (n1 % n2 == 0) return n2;
    n1 %= n2;
    if (n2 % n1 == 0) return n1;
    n2 %= n1;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  cout << GCD(N, M) << endl;
  return 0;
}
