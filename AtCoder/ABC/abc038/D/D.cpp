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

typedef pair<int, int> pii;
typedef vector<pii> vpii;

bool greater_smaller(pii lhs, pii rhs) {
  if (lhs.first == rhs.first) return lhs.second < rhs.second;
  return lhs.first > rhs.first;
}

int LIS(vpii input_vec){
  int N = input_vec.size();
  int L[N];
  fill(L, L+N, -1);
  int buf;
  int cur_len = 0;
  int left, right, mid, bef_mid;
  rep(i, N) {
    buf = input_vec[N-i-1].second;
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
  return cur_len;
}

int main() {
  int N;
  cin >> N;
  int a, b;
  vpii boxes;
  rep(i, N) {
    cin >> a >> b;
    boxes.push_back(make_pair(a, b));
  }
  sort(boxes.begin(), boxes.end(), greater_smaller);
  if (debug_mode) rep(i, boxes.size()) cout << boxes[i].first << ' ' << boxes[i].second << endl;
  cout << LIS(boxes) << endl;
  return 0;
}
