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
  int N;
  string C;
  cin >> C;
  int cur_ind = 0;
  rep(i, C.length()) {
    if (C.length() == cur_ind) break;
    if (C[cur_ind] == 'k' || C[cur_ind] == 'o' || C[cur_ind] == 'u') {
      cur_ind++;
      continue;
    } else if (C.length() - 1 > cur_ind) {
      if (C[cur_ind] == 'c' && C[cur_ind+1] == 'h') {
        cur_ind += 2;
        continue;
      } else {
        cout << "NO" << endl;
        return 0;
      }
    } else {
        cout << "NO" << endl;
        return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
