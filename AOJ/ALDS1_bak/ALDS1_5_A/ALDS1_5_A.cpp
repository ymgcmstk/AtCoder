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

bool check_ans(int query, vector<int>* input, int cur) {
  if (input->size() == cur) return false;
  if ((*input)[cur] == query) return true;
  return check_ans(query-(*input)[cur], input, cur+1) || check_ans(query, input, cur+1);
}

int main() {
  int N, M, query;
  cin >> N;
  vector<int>* input = new vector<int>(N);
  // vector<int> input(N);
  rep(i, N) cin >> (*input)[i];
  cin >> M;
  // vector<int> query(M);
  rep(i, M) {
    cin >> query;
    if (check_ans(query, input, 0)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
