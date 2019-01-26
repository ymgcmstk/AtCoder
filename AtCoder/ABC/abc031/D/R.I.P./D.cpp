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

bool debug_mode = false;

bool check_func(vector<string> v, vector<string> w, vector<string> ans) {
  rep(i, w.size()) {
    string temp = "";
    rep(j, v[i].size()) {
      temp += ans[int(v[i][j] - '1')];
    }
    if (w[i] != temp) return false;
  }
  return true;
}

int main() {
  int K, N;
  cin >> K >> N;
  vector<string> v, w, ans_first, ans_last, ans;
  string temp;
  rep(i, K) {
    ans.push_back("");
    ans_first.push_back("");
    ans_last.push_back("");
  }
  rep(i, N) {
    cin >> temp;
    v.push_back(temp);
    cin >> temp;
    w.push_back(temp);
  }
  rep(i, N) {
    int af_ind = int(v[i][0] - '1');
    if (ans[af_ind] == "") {
      int end = w[i].size() - v[i].size() + 1;
      ans[af_ind] = w[i].substr(0, end);
    } else {
      int cur_ind = 0;
      while (ans[af_ind][cur_ind] == w[i][cur_ind]) cur_ind++;
      ans[af_ind] = ans[af_ind].substr(0, cur_ind);
    }
    int al_ind = int(v[i][v[i].size()-1] - '1');
    if (ans[al_ind] != "") {
    }
  }
  while (!check_func(v, w, ans)) {

  }
  return 0;
}
