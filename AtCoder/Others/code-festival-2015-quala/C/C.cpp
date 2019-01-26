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
  int N, T;
  cin >> N >> T;
  int S1[N];
  int S2[N];
  fill(S1, S1+N, T+1);
  fill(S2, S2+N, T+1);
  bool flg;
  int flg_ind;
  int cur_sum = 0;
  priority_queue<int> pq;
  int temp1, temp2;
  rep(i, N) {
    cin >> temp1 >> temp2;
    cur_sum += temp1;
    pq.push(temp1 - temp2);
  }
  rep(i, N) {
    if (cur_sum <= T) {
      cout << i << endl;
      return 0;
    }
    temp1 = pq.top();
    pq.pop();
    cur_sum -= temp1;
  }
  if (cur_sum <= T) cout << N << endl;
  else cout << -1 << endl;
  return 0;
}
