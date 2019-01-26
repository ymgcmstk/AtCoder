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
  int num = (int)('Z' - 'A') + 1;
  int S1[num];
  int S2[num];
  int S3[num];
  fill(S1, S1+num, 0);
  fill(S2, S2+num, 0);
  fill(S3, S3+num, 0);
  string temp;
  cin >> temp;
  rep(i, temp.length()) S1[temp[i] - 'A']++;
  cin >> temp;
  rep(i, temp.length()) S2[temp[i] - 'A']++;
  cin >> temp;
  rep(i, temp.length()) S3[temp[i] - 'A']++;
  N = temp.length()/2;
  // check whether we can generate S3 by using all characters in S1 and S2
  int s1num = 0;
  int s2num = 0;
  rep(i, num) {
    if (S3[i] > S1[i] + S2[i]) {
      cout << "NO" << endl;
      return 0;
    }
    s1num += max(0, S3[i] - S2[i]);
    s2num += max(0, S3[i] - S1[i]);
  }

  if (s1num > N || s2num > N) cout << "NO" << endl;
  else cout << "YES" << endl;
  // check whether we can generate S3 using N characters from S1 and S2 respectively
  // source code
  return 0;
}
