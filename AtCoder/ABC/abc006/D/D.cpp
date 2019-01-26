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
  int C[N];
  int ML[N+1];
  fill(ML, ML+N+1, MOD);
  int cur_max = 1;
  ML[0] = 0;
  int left, right, mid;
  rep(i, N) {
    cin >> C[i];
    left = 1;
    right = cur_max + 1;
    while (true) {
      mid = (left + right) / 2;
      /*
        ML[mid] > C[i] && ML[mid-1] <= C[i]となるようなmidを見つけたい
        ML[i] < ML[i+1]が成り立つ
       */
      if (ML[mid] <= C[i]) left = mid;
      else if (ML[mid-1] > C[i]) right = mid;
      else break;
    }
    ML[mid] = C[i];
    if (mid == cur_max) cur_max++;
  }
  cout << N - cur_max + 1 << endl;
  return 0;
}
