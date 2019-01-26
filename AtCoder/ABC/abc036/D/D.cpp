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

bool debug_mode = false;

typedef vector<vector<int> > vvi;

const int WHITE = 0;
const int BLACK = 1;

void calc_tree(int cur_ind, int prev_ind, int color, int* prev_num, vvi tree) {
  int cur_num;
  cur_num = 1;
  rep(i, tree[cur_ind].size()) {
    if (tree[cur_ind][i] == prev_ind) continue;
    int cur_white, cur_black;
    cur_white = 0;
    cur_black = 0;
    calc_tree(tree[cur_ind][i], cur_ind, WHITE, &cur_white, tree);
    if (color == WHITE) {
      calc_tree(tree[cur_ind][i], cur_ind, BLACK, &cur_black, tree);
    }
    int temp = (cur_white + cur_black) % MOD;
    cur_num = (cur_num * temp) % MOD;
  }
  *prev_num = cur_num;
}

int calc_num(vvi tree){
  int white, black;
  white = 1;
  black = 1;
  int cur_ind = 0;
  int prev_ind = -1;
  calc_tree(cur_ind, prev_ind, WHITE, &white, tree);
  calc_tree(cur_ind, prev_ind, BLACK, &black, tree);
  return (white + black) % MOD;
}

int main() {
  int N;
  cin >> N;
  vvi tree;
  rep(i, N) tree.push_back(vector<int>());
  int a, b;
  rep(i, N-1) {
    cin >> a >> b;
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  cout << calc_num(tree) << endl;
  return 0;
}
