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

bool check_func2(vector<string> v, vector<string> w, int ans_len) {
  vector<int> char_len;
  int temp = ans_len;
  rep(i, 9) {
    char_len.push_back(temp % 3 + 1);
    temp /= 3;
  }
  if (temp > 0) cout << "something wrong" << endl;
  rep(i, w.size()) {
    // int temp = w[i].size();
    int sum_length = 0;
    rep(j, v[i].size()) {
      sum_length += char_len[int(v[i][j] - '1')];
    }
    if (sum_length != w[i].size()) return false;
  }
  return true;
}

vector<string> get_str(vector<string> v, vector<string> w, vector<int> char_len) {
  vector<string> strs;
  rep(i, 9) strs.push_back("");
  rep(i, w.size()) {
    int sum_length = 0;
    rep(j, v[i].size()) {
      string this_str = w[i].substr(sum_length, char_len[int(v[i][j] - '1')]);
      if (strs[int(v[i][j] - '1')] == "") strs[int(v[i][j] - '1')] = this_str;
      else if (strs[int(v[i][j] - '1')] != this_str) return vector<string>();
      sum_length += char_len[int(v[i][j] - '1')];
    }
  }
  return strs;
}

int main() {
  int K, N;
  cin >> K >> N;
  vector<string> v, w, ans_len;
  string temp;
  rep(i, N) {
    cin >> temp;
    v.push_back(temp);
    cin >> temp;
    w.push_back(temp);
  }

  int cur_state = 0;
  vector<int> char_len;
  while (true) {
    if (!check_func2(v, w, cur_state)) {
      cur_state++;
      continue;
    }
    char_len = vector<int>();
    int temp_num = cur_state;
    rep(i, 9) {
      char_len.push_back(temp_num % 3 + 1);
    temp_num /= 3;
    }
    if (get_str(v, w, char_len).size() == 0) {
      cur_state++;
      continue;
    }
    break;
  }
  vector<string> the_ans = get_str(v, w, char_len);
  int cur_ind = 0;
  while (the_ans[cur_ind].length() > 0) {
    cout << the_ans[cur_ind] << endl;
    cur_ind++;
  }

  return 0;
}
