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

int main() {
  int N;
  cin >> N;
  int a[N];
  rep(i, N) cin >> a[i];
  int all_taka_max = -MOD;
  rep(i, N) {
    int taka_max = -MOD;
    int flg = 0;
    int aoki_max = -MOD;
    int max_ind = MOD;
    if (i > 0) {
      int cur_ind = i - 1;
      int cur_sum = 0;
      int taka_sum = 0;
      while (cur_ind >= 0) {
        cur_sum += a[cur_ind+1];
        taka_sum += a[cur_ind];
        if (cur_sum >= aoki_max) {
          aoki_max = cur_sum;
          max_ind = cur_ind;
          taka_max = taka_sum;
          // flg = 0;
        }
        cur_ind -= 2;
      }
    }
    if (i > 1) {
      int cur_ind = i - 2;
      int cur_sum = 0;
      int taka_sum = a[i];
      while (cur_ind >= 0) {
        cur_sum += a[cur_ind+1];
        taka_sum += a[cur_ind];
        if (cur_sum == aoki_max && max_ind > cur_ind) {
          max_ind = cur_ind;
          taka_max = taka_sum;
          flg = 1;
        } else if (cur_sum > aoki_max) {
          aoki_max = cur_sum;
          max_ind = cur_ind;
          taka_max = taka_sum;
          flg = 1;
        }
        cur_ind -= 2;
      }
    }
    if (i < N-2) {
      int cur_ind = i;
      int cur_sum = 0;
      int taka_sum = 0;
      while (cur_ind < N-1) {
        cur_sum += a[cur_ind+1];
        taka_sum += a[cur_ind];
        if (cur_sum > aoki_max) {
          aoki_max = cur_sum;
          max_ind = cur_ind;
          taka_max = taka_sum;
          flg = 2;
        }
        cur_ind += 2;
      }
    }
    all_taka_max = max(all_taka_max, taka_max);
  }
  cout << all_taka_max << endl;
  return 0;
}
