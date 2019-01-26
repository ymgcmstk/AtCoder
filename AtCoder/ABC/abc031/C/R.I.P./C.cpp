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
  int a_sum[N];
  int a_sum_min[N];
  int a_sum_max[N];
  int a_sum_min_ind[N];
  int a_sum_max_ind[N];
  fill(a_sum, a_sum+N, 0);
  fill(a_sum_min, a_sum_min+N, 0);
  fill(a_sum_max, a_sum_max+N, 0);
  // fill(aoki_max, aoki_max+N, 0);
  rep(i, N) cin >> a[i];
  a_sum[0] = a[0];
  a_sum[1] = a[1];
  a_sum_min[0] = a[0];
  a_sum_min[1] = a[1];
  a_sum_max[N-2] = a[N-2];
  a_sum_max[N-1] = a[N-1];
  a_sum_min_ind[0] = 0;
  a_sum_min_ind[1] = 1;
  a_sum_max_ind[N-1] = N-1;
  a_sum_max_ind[N-2] = N-2;
  repd(i, 2, N) {
    a_sum[i] = a_sum[i-2] + a[i];
    if (a_sum_min[i-2] > a_sum[i]) {
      a_sum_min[i] = a_sum[i];
      a_sum_min_ind[i] = i;
    } else {
      a_sum_min[i] = a_sum_min[i-2];
      a_sum_min_ind[i] = i-2;
    }
  }
  mrep(i, N-2) {
    a_sum_max[i] = max(a_sum_max[i+2], a_sum[i]);
  }
  mrep(i, N-2) {
    if (a_sum_max[i] < a_sum[i]) {
      a_sum_max[i] = a_sum[i];
      a_sum_max_ind[i] = i;
    } else {
      a_sum_max[i] = a_sum_max[i+2];
      a_sum_max_ind[i] = i+2;
    }
  }
  // rep(i, N) {
  // aoki_max[i] = max(max(a_sum[i] - a_sum_min[i], a_sum[max(i-1, 0)] - a_sum_min[max(i-1, 0)]), a_sum_max[i] - a_sum[i]);
  // }
  int taka_max = -MOD;
  if (a[0] + a[2] < a[1]) taka_max = max(a[1], a[0] + a[2]);
  int left_odd, left_even, right;
  rep(i, N) {
    if (i > 1) left_odd = a_sum[i-1] - a_sum_min[i-3];
    else left_odd = -MOD;
    if (i > 0) left_even = a_sum[i] - a_sum_min[i-2];
    else left_even = -MOD;
    if (i < N - 1) right = a[i] + a_sum_max[i+2] - a_sum[i];
    if (right > left_odd && right > left_even) {
      taka_max = max(taka_max, a_sum[a_sum_max_ind[i+2]-1] - a_sum[i+1]);
    } else {
      if (left_odd == left_even) {
      }
    }
  }
  return 0;
}
