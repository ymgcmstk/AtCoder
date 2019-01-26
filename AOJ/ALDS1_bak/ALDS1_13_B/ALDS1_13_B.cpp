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

typedef vector<vector<int> > vvi;

typedef pair<string, int> si;

string convert_string(vvi V) {
  string ans = "";
  rep(i, 3) rep(j, 3) ans += V[i][j];
  return ans;
}

void add_queue(queue<string> &Q_s, queue<int> &Q_i, set<string> &generated) {
  string cur_str = Q_s.front();
  int cur_i = Q_i.front();
  int zero_ind = cur_str.find("0");
  string new_str;
  // cout << cur_str << endl;
  if (zero_ind % 3 != 0) {
    new_str = cur_str;
    swap(new_str[zero_ind], new_str[zero_ind-1]);
    if (generated.find(new_str) == generated.end()) {
      Q_s.push(new_str);
      Q_i.push(cur_i+1);
      generated.insert(new_str);
    }
  }
  if (zero_ind % 3 != 2) {
    new_str = cur_str;
    swap(new_str[zero_ind], new_str[zero_ind+1]);
    if (generated.find(new_str) == generated.end()) {
      Q_s.push(new_str);
      Q_i.push(cur_i+1);
      generated.insert(new_str);
    }
  }
  if (zero_ind < 6) {
    new_str = cur_str;
    swap(new_str[zero_ind], new_str[zero_ind+3]);
    if (generated.find(new_str) == generated.end()) {
      Q_s.push(new_str);
      Q_i.push(cur_i+1);
      generated.insert(new_str);
    }
  }
  if (zero_ind >= 3) {
    new_str = cur_str;
    swap(new_str[zero_ind], new_str[zero_ind-3]);
    if (generated.find(new_str) == generated.end()) {
      Q_s.push(new_str);
      Q_i.push(cur_i+1);
      generated.insert(new_str);
    }
  }
  Q_s.pop();
  Q_i.pop();
}


int main() {
  // vvi MAP(3);
  char temp;
  string initial_state;
  rep(i, 9) {
    cin >> temp;
    initial_state += temp;
  }
  set<string> generated;
  queue<string> Q_s;
  queue<int> Q_i;
  Q_s.push(initial_state);
  Q_i.push(0);
  while (Q_s.front() != "123456780" && (!Q_s.empty())) add_queue(Q_s, Q_i, generated);
  cout << Q_i.front() << endl;
  return 0;
}
