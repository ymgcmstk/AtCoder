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
#include <stdlib.h>

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
  string S;
  cin >> S;
  string A = "";
  string C = "";
  int temp = 1;
  C = S[0];
  repd(i, 1, S.length()) {
    if (C[0] == S[i]) {
      temp += 1;
    } else {
      A += C;
      A += to_string(int(temp));
      temp = 1;
      C = S[i];
    }
  }
  A += C;
  A += to_string(int(temp));
  cout << A << endl;
  return 0;
}
