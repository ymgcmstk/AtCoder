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
  set<int> S, H, C, D;
  char mark;
  int temp;
  rep(i, N) {
    cin >> mark >> temp;
    if (mark == 'S') S.insert(temp);
    else if (mark == 'H') H.insert(temp);
    else if (mark == 'C') C.insert(temp);
    else if (mark == 'D') D.insert(temp);
  }
  repd(i, 1, 14) {
    if (S.find(i) == S.end()) cout << 'S' << ' ' << i << endl;
  }
  repd(i, 1, 14) {
    if (H.find(i) == H.end()) cout << 'H' << ' ' << i << endl;
  }
  repd(i, 1, 14) {
    if (C.find(i) == C.end()) cout << 'C' << ' ' << i << endl;
  }
  repd(i, 1, 14) {
    if (D.find(i) == D.end()) cout << 'D' << ' ' << i << endl;
  }
  // source code
  return 0;
}
