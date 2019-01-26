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
  string S;
  cin >> S;
  int centor = 1e+5;
  int length = 2 * centor + 1;
  int score[length];
  fill(score, score + length, -MOD);
  int min_ind = centor;
  int max_ind = centor;
  score[centor] = 0;
  int cur_ind;
  rep(i, S.length()) {
    if (S[i] == 'M') {
      min_ind--;
      max_ind++;
      cur_ind = min_ind;
      while (cur_ind <= max_ind) {
        score[cur_ind] = max(score[cur_ind-1], score[cur_ind+1]);
        cur_ind += 2;
      }
    } else if (S[i] == '+') {
      cur_ind = min_ind;
      while (cur_ind <= max_ind) {
        score[cur_ind] += cur_ind - centor;
        cur_ind += 2;
      }
    } else if (S[i] == '-') {
      cur_ind = min_ind;
      while (cur_ind <= max_ind) {
        score[cur_ind] -= cur_ind - centor;
        cur_ind += 2;
      }
    } else {
      cout << "The input may be wrong." << endl;
      return -1;
    }
  }
  cout << score[centor] << endl;
  return 0;
}
