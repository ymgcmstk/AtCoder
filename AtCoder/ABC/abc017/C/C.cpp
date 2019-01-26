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
#define rep(i,n) repd(i,0,n)
#define LL long long

using namespace std;

bool boolfunc(bool a, int b){
  if (b < 0) return false;
  else return a;
}

int input_value(){
  int a;
  cin >> a;
  return a;
}

void input_array(int * p, int a){
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
  if(precision > 0){
    cout << setprecision(precision)  << a << "\n";
  } else {
    cout << a << "\n";
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  int l[N], r[N], s[N];
  rep(i, N) {
    cin >> l[i] >> r[i] >> s[i];
  }
  int cur_max = 0;
  int cur_sum = 0;
  rep(i, M) {
    cur_sum = 0;
    int _i = i+1;
    rep(j, N) {
      if (l[j] > _i || r[j] < _i) cur_sum += s[j];
    }
    cur_max = max(cur_max, cur_sum);
  }
  cout << cur_max << endl;
  return 0;
}
