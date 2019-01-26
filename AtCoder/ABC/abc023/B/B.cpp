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

string generate_str(int cur, int N, string s) {
  if (N == cur) return s;
  if (cur % 3 == 0) return "b" + generate_str(cur+1, N, s) + "b";
  if (cur % 3 == 1) return "a" + generate_str(cur+1, N, s) + "c";
  if (cur % 3 == 2) return "c" + generate_str(cur+1, N, s) + "a";
  return s;
}

bool debug_mode = true;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = N / 2;
  if ((N - 1) % 2 == 1) {
    cout << -1 << endl;
    return 0;
  }
  /*

  else if (S == generate_str(1, ans+1, "b")) cout << ans << endl;
  else cout << -1 << endl;
  if (debug_mode) cout << generate_str(1, ans+1, "b") << endl;
  */
  string cur_s = "b";
  rep(i, ans / 3) cur_s = "bca" + cur_s + "cab";
  int fans = ans;
  ans %= 3;
  if (ans == 1) cur_s = "a" + cur_s + "c";
  else if (ans == 2) cur_s = "ca" + cur_s + "ca";
  if (S == cur_s) cout << fans << endl;
  else cout << -1 << endl;

  return 0;
}
