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

int main() {
  int N, M;
  cin >> N >> M;
  int alp = 'Z' - 'A' + 1;
  int alp_count1[alp];
  int alp_count2[alp];
  fill(alp_count1, alp_count1+alp, 0);
  fill(alp_count2, alp_count2+alp, 0);
  char temp;
  rep(i, N) {
    cin >> temp;
    alp_count2[temp - 'A']++;
  }
  rep(i, M) {
    cin >> temp;
    alp_count1[temp - 'A']++;
  }
  int cur_max = 0;
  rep(i, alp) {
    if (alp_count1[i] == 0) {
      if (alp_count2[i] > 0) {
        cout << -1 << endl;
        return 0;
      }
      continue;
    }
    if (alp_count2[i] == 0) continue;
    cur_max = max(cur_max, (alp_count2[i] - 1) / alp_count1[i] + 1);
  }
  cout << cur_max << endl;
  return 0;
}
