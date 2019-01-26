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
  N++;
  int cd2case[N];
  int case2cd[N];
  rep(i, N) {
    case2cd[i] = i;
    cd2case[i] = i;
  }
  case2cd[0] = 0;
  cd2case[0] = 0;
  int cur_disk = 0;
  int next_disk = 0;
  rep(i, M) {
    cin >> next_disk;
    if (next_disk == cur_disk) continue;
    int cur_ind = 1;
    cur_ind = cd2case[next_disk];
    case2cd[cur_ind] = cur_disk;
    cd2case[cur_disk] = cur_ind;
    cd2case[next_disk] = 0;
    cur_disk = next_disk;
  }
  repd(i, 1, N) {
    cout << case2cd[i] << endl;
  }
  return 0;
}
