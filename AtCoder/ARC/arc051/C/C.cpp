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
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> num(N);
  vector<bool> num_flg(N, false);
  rep(i, N) cin >> num[i];
  if (A == 1) {
    sort(num.begin(), num.end());
    rep(i, N) cout << num[i] << endl;
  } else {
    vector<int> count(N, 0);
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > minpq;
    rep(i, N) minpq.push(make_pair(log(num[i])/log(A), i));
    pair<double, int> cur_pdi;
    int i = 0;
    int checked_num = 0;
    int inc_num;
    while (i < B) {
      // cout << i << endl;
      if (checked_num == N && (B - i) >= N) {
        rep(cur_targ, N) count[cur_targ] += (B - i) / N;
        i = B - (B - i) % N;
        continue;
      }
      cur_pdi = minpq.top();
      minpq.pop();
      inc_num = min(int(minpq.top().first - cur_pdi.first + 1), B - i);
      cur_pdi.first += inc_num;
      count[cur_pdi.second] += inc_num;
      i += inc_num;
      if (!num_flg[cur_pdi.second]) {
        num_flg[cur_pdi.second] = true;
        checked_num++;
      }
      if (debug_mode) cout << cur_pdi.second << ' ' << inc_num << ' ' << count[cur_pdi.second] << endl;
      minpq.push(cur_pdi);
    }
    vector<LL> A_num;
    A_num.push_back(A);
    LL target, cur_count, cur_val;
    LL cur_A;
    int cur_step = 0;
    while (minpq.size() > 0) {
      cur_pdi = minpq.top();
      minpq.pop();
      target = cur_pdi.second;
      cur_count = 0;
      cur_A = A;
      cur_val = 1;
      while ((1 << cur_count) <= count[target]) {
        if (((1 << cur_count) & count[target]) > 0) cur_val = (cur_val * cur_A) % MOD;
        cur_A = (cur_A * cur_A) % MOD;
        cur_count++;
      }
      if (debug_mode) cout << target << ' ' << count[target] << ' ' << (cur_val * num[target]) % MOD << endl;
      else cout << (cur_val * num[target]) % MOD << endl;
    }
  }
  return 0;
}
