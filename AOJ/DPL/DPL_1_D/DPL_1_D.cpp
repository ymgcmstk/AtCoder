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

int main() {
  int N;
  cin >> N;
  int L[N];
  fill(L, L+N, -1);
  int buf;
  int cur_len = 0;
  int left, right, mid, bef_mid;
  rep(i, N) {
    cin >> buf;
    if (L[0] > buf || L[0] == -1) L[0] = buf;
    else {
      left = 1;
      right = cur_len;
      bef_mid = -1;
      mid = (left + right) / 2;
      while (mid != bef_mid) {
        if (L[mid-1] < buf && L[mid] > buf) {
          L[mid] = buf;
          break;
        } else if (L[mid] == buf) break;
        else if (L[mid] < buf) left = mid;
        else right = mid;
        bef_mid = mid;
        mid = left + right;
        mid /= 2;
      }
    }
    if (i == 0) {
      cur_len++;
      continue;
    }
    if (L[cur_len-1] < buf) {
      L[cur_len] = buf;
      cur_len++;
    }
  }
  cout << cur_len << endl;
  return 0;
}
// O(N * log(length))
