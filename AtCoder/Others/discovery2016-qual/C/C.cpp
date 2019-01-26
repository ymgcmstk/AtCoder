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

string get_smallest_str(string S, int K) {
  string ans = S;
  string temp;
  int cur_targ = 0;
  rep(i, K) {
    while (ans[cur_targ] == 'a') cur_targ++;
    ans[cur_targ] = 'a';
    // temp = ans.substr(0, cur_targ) + ans.substr(cur_targ+1, ans.length() - cur_targ - 1);
    // if (ans > temp) ans = temp;
  }
  return ans;
}

int main() {
  int K;
  string S;
  cin >> S;
  cin >> K;
  /*
    取りうる動作は次の3種類
    1. 前にaをたす
    2-1. 前から数えて最初に現れたaでないものを消す
    2-2. 前から数えて最初に現れたaでないものをaにする
    1と2-1 + 2-2をi, K-i回それぞれ行うときの最小を求める
    'a' * i + get_smallest_str(S, K-i);
   */

  int non_a = 0;
  rep(i, S.length()) if (S[i] != 'a') non_a++;
  if (non_a <= K) {
    cout << string(S.length() - K, 'a') << endl;
    return 0;
  }

  string cur_smallest = S;
  string a_store = "";

  rep(i, K+1) {
    string temp = a_store;
    temp += get_smallest_str(S, K-i);
    if (temp < cur_smallest) cur_smallest = temp;
    a_store += "a";
  }
  cout << cur_smallest << endl;
  return 0;
}
