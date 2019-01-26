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

bool debug_mode = false;

int main() {
  string S;
  cin >> S;
  vector<int> scores;
  int cur_score = 0;
  mrep(i, S.length()) {
    if (S[i] == 'M') scores.push_back(cur_score);
    else if (S[i] == '+') cur_score++;
    else if (S[i] == '-') cur_score--;
    else cout << "The input may be wrong." << endl;
  }
  sort(scores.begin(), scores.end());
  if (debug_mode) {
    rep (i, scores.size()) cout << scores[i] << ' ';
    cout << endl;
  }
  int sum = 0;
  rep(i, scores.size()/2) {
    sum += scores[i+scores.size()/2];
    sum -= scores[i];
  }
  cout << sum << endl;
  return 0;
}
