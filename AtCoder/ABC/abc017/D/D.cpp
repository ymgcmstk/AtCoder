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
  int f[N+1];
  int s[N+1];
  f[0] = 0;
  rep(i, N) cin >> f[i+1];
  rep(i, N+1) s[i] = 0;
  s[0] = 1;
  set<int> drug;
  rep(i, N) {
    drug.clear();
    repd(j, i+1, N+1) {
      if (!(drug.find(f[j]) == drug.end())) {
        break;
      }
      drug.insert(f[j]);
      s[j] += s[i];
      if (s[j] > 1000000007) s[j] %= 1000000007;
    }
  }

  // source code
  cout << s[N] << endl;
  return 0;
}
