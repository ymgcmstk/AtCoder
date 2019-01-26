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

template <typename T>
void show_array(T arr[]) {
  rep(i, sizeof(*arr)/sizeof(arr[0])) cout << arr[i] << ' ';
  cout << endl;
}


template <typename T>
void show_vec(vector<T> vec) {
  rep(i, vec.size()) cout << vec[i] << ' ';
  cout << endl;
}

bool debug_mode;

int main() {
  int num[5];
  rep(i, 5) cin >> num[i];
  vector<int> temp_vec;
  set<int> temp_set;
  rep(i, 3) {
    repd(j, i+1, 4) {
      repd(k, j+1, 5) {
        if (temp_set.find(num[i] + num[j] + num[k]) != temp_set.end()) continue;
        temp_vec.push_back(num[i] + num[j] + num[k]);
        temp_set.insert(num[i] + num[j] + num[k]);
      }
    }
  }
  sort(temp_vec.begin(), temp_vec.end());
  cout << temp_vec[temp_vec.size()-3] << endl;

  return 0;
}
