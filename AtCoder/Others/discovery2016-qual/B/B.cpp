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

LL calc_loop(LL start, vector<LL> A) {
  LL ans = 0;
  vector<LL> B;
  rep(i, A.size()) B.push_back(A[i]);
  sort(B.begin(), B.end());
  LL cur_head = start;
  LL cur_head_B = 0;
  while (cur_head_B < B.size()) {
    if (cur_head == start) ans++;
    if (A[cur_head] == B[cur_head_B]) cur_head_B++;
    cur_head++;
    cur_head %= B.size();
  }
  return ans;
}

int main( ) {
  int N;
  cin >> N;
  vector<LL> A(N);
  LL min_val = MOD;
  vector<LL> min_vec;

  rep(i, N) {
    cin >> A[i];
    if (A[i] < min_val) {
      min_val = A[i];
      min_vec = vector<LL>(1);
      min_vec[0] = i;
    } else if (A[i] == min_val) min_vec.push_back(i);
  }

  LL ans = 2 * N;
  LL cur_ans;
  rep(i, min_vec.size()) {
    cur_ans = calc_loop(min_vec[i], A);
    ans = min(ans, cur_ans);
  }
  cout << ans << endl;
  return 0;
}
