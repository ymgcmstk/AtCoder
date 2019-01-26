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

const char IN = 0;
const char LEFT = -1;
const char RIGHT = 1;


template <typename T>
class W {
public:
  T left, right;
  W () {}
  W (T left, T right) : left(left), right(right) {}
  char in(T m) {
    if (this->left > m) return LEFT;
    if (this->right < m) return RIGHT;
    return IN;
  }
};

int main() {
  int N;
  cin >> N;
  float start, end;
  cin >> start >> end;
  vector<W<float> > Ws(N+1);
  float temp_l, temp_r;
  rep(i, N + 1) {
    cin >> temp_l >> temp_r;
    temp_r += temp_l;
    Ws[i] = W<float>(temp_l, temp_r);
  }
  float paths[N+1];
  rep(i, N + 1) {
    paths[i] = start * (N - i) + end * i;
    paths[i] /= N;
  }
  int cur_ind;
  vector<int> corners;
  corners.push_back(0);
  corners.push_back(N);

  return 0;
}
