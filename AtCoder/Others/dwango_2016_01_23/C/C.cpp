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

typedef vector<vector<int> > vii;

struct Node {
  int max_t;
  int place;
  int ord_t;
  Node () {};
};

int main() {
  int N, M, src, dst;
  cin >> N >> M >> src >> dst;
  int L[M];
  vii ways_w;
  vii ways_s;
  int temp;
  rep(i, M) {
    cin >> L[i];
    vector<int> this_w;
    vector<int> this_s;
    rep(j, L[i]) {
      cin >> temp;
      this_w.push_back(temp);
    }
    rep(j, L[i]-1) {
      cin >> temp;
      this_s.push_back(temp);
    }
    ways_w.push_back(this_w);
    ways_s.push_back(this_s);
  }
  return 0;
}
