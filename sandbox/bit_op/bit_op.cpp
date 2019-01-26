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

template <typename T>
inline string to_bin_str(T n) {
  std::string str;
  while (n > 0) {
    str.push_back('0' + (n & 1));
    n >>= 1;
  }
  std::reverse(str.begin(), str.end());
  return str;
}


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

void insert_M_to_N() {
  int N, M, start_i;
  cout << "Input N:" << endl;
  cin >> N;
  cout << "Input M:" << endl;
  cin >> M;
  cout << "Input i:" << endl;
  cin >> start_i;
  cout << "N: " << to_bin_str(N) << endl;
  cout << "M: " << to_bin_str(M) << endl;
  int len_M = to_bin_str(M).length();
  int new_N = N;
  new_N = N & ((1 << start_i) - 1);
  N = N & (~0 << (start_i + len_M));
  N += (M << start_i) + new_N;
  cout << "N: " << to_bin_str(N) << endl;
}

bool get_bit(int N, int p) {
  if (((N >> p) & 1) == 1) return true;
  else return false;
}

int set_bit(int N, int p, bool torf) {
  if (torf) return N | (1 << p);
  else if (!torf && get_bit(N, p)) return N - (1 << (p));
  else return N;
}

void get_smaller_and_larger_num () {
  int N;
  cin >> N;
  cout << "Input N:" << endl;
  cout << "N: " << to_bin_str(N) << endl;
  int bn;

  int f_zero = 0;
  while (!get_bit(N, f_zero)) f_zero++;
  while (get_bit(N, f_zero)) f_zero++;
  bn = set_bit(set_bit(N, f_zero, 1), f_zero-1, 0);

  cout << "larger one than N: " << to_bin_str(bn) << endl;

  int f_one = 0;
  while (get_bit(N, f_one)) f_one++;
  while (!get_bit(N, f_one)) f_one++;
  bn = set_bit(set_bit(N, f_one, 0), f_one-1, 1);

  cout << "smaller one than N: " << to_bin_str(bn) << endl;
}

void check_2_ruijo() {
  repd(i, 1, 18) cout << i << ' ' << to_bin_str(i) << ' ' << ((i & (i-1)) == 0) << endl;
}

void temp() {
  int N, M, start_i;
  cout << "Input N:" << endl;
  cin >> N;
  cout << "Input M:" << endl;
  cin >> M;
  cout << "N: " << to_bin_str(N) << endl;
  cout << "M: " << to_bin_str(M) << endl;
  int cur_num = N ^ M;
  int all = 0;
  while (cur_num > 0) {
    if ((cur_num & 1) == 1) all++;
    cur_num >>= 1;
  }
  cout << all << endl;
}

int main() {
  // insert_M_to_N();
  int N;
  cout << "Input N:" << endl;
  cin >> N;
  cout << "N: " << to_bin_str(N) << endl;
  N = N | (N >> 1);
  cout << "N: " << to_bin_str(N) << endl;
}
