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

bool debug_mode = true;

LL count_forbidden_num(LL A) {
  LL ans = 0;
  LL cur_temp = A;
  LL cur_temp2 = 1;
  LL temp;
  if (A < 10 && false) {
    if (A < 4) {
      ans = A;
    } else if (A < 9) {
      ans = A - 1;
    } else {
      ans = A - 2;
    }
    return ans;
  }
  int ten_num = 0;
  while (cur_temp >= pow(10, 1+ten_num)) ten_num++;
  temp = 1;
  temp = pow(2, 3 * ten_num);
  ten_num++;
  LL div;
  while (temp > 0) {
    div = pow(10, ten_num);
    if (debug_mode) cout << "first div: "  << div << endl;
    ten_num--;
    LL head = cur_temp % div;
    div = pow(10, ten_num);
    head = head / div;
    if (debug_mode) cout << "head: "  << head << endl;
    if (head == 4) {
      ans += temp * 4;
      ans -= 1;
      break;
    } else if (head == 9) {
      ans += temp * 8;
      ans -= 1;
      break;
    }
    if (head < 4) {
      ans += temp * head;
    } else if (head < 9) {
      ans += temp * (head - 1);
    }
    temp /= 8;
  }
  // string a_str = to_string(A);
  ans += 1;
  // if (a_str.find('4') > a_str.length() && a_str.find('9') > a_str.length()) ans += 1;
  // if (ten_num == 0 && head != 4 && head != 9) ans += 1;
  return ans;
}
/*
int count_awesome_num(int A) {
  int ans = 0;
  rep(i, A+1) {
    string str = to_string(i);
    if (str.find('4') > str.length() && str.find('9') > str.length()) ans++;
  }
  return ans;
}
*/
int main() {
  LL A, B;
  cin >> A >> B;
  LL ans = 0;
  debug_mode = false;
  // cout << B - (A) - count_forbidden_num(B) + count_forbidden_num(A)<< endl;
  cout << B - (A - 1) - count_forbidden_num(B) + count_forbidden_num(A - 1) << endl;

  bool test_mode = false;

  /*
  if (test_mode) {
    // cout << count_awesome_num(10) == count_forbidden_num(10) << endl;
    rep(i, 1000) {
      int awe = count_awesome_num(i);
      int forb = count_forbidden_num(i);
      if (awe != forb) {
        cout << i << ": " << awe << "(true), " << forb << "(mine)" << endl;
      }
    }
  }
  */
  if (debug_mode) {
    cout << 39 << ' ' << 40 << endl;
    cout << count_forbidden_num(39) << endl;
    cout << count_forbidden_num(40) << endl;
    // cout << count_forbidden_num(0) << endl;
    cout << 1 << ' ' << count_forbidden_num(1) << endl;
    cout << 9 << ' ' << count_forbidden_num(9) << endl;
  }
  return 0;
}
