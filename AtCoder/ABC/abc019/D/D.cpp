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
  cin >> N;
  int cur_max, cur_ind;
  int temp;
  cur_max = -1;
  rep(i, N) {
    if (i == 0) continue;
    cout << "? " << 1 << " " << i+1 << endl;
    cin >> temp;
    if (cur_max < temp) {
      cur_ind = i;
      cur_max = temp;
    }
  }
  rep(i, N) {
    if (i == cur_ind) continue;
    cout << "? " << cur_ind+1 << " " << i+1 << endl;
    cin >> temp;
    cur_max = max(cur_max, temp);
  }
  cout << "! " << cur_max << endl;
  return 0;
}
