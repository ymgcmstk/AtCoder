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

bool boolfunc(bool a, int b){
  if (b < 0) return false;
  else return a;
}

int input_value(){
  int a;
  cin >> a;
  return a;
}

void input_array(int * p, int a){
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
  if(precision > 0){
    cout << setprecision(precision)  << a << "\n";
  } else {
    cout << a << "\n";
  }
}

struct Node {
  int depth, par;
  Node() {}
  Node(int depth, int par) : depth(depth), par(par) {}
};

typedef vector<Node> Tree;

int main() {
  int N, Q;

  // 1. 木の作成
  cin >> N;
  vector<int> x(N);
  vector<int> y(N);
  rep(i, N-1) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  Tree T = Tree(N);
  T[0].par = -1;
  T[0].depth = 0;
  set<int> tree_el = set<int>();
  tree_el.insert(0);
  while (tree_el.size() < N) {
    mrep(i, x.size()) {
      if (tree_el.find(x[i]) != tree_el.end()) {
        T[y[i]].par = x[i];
        T[y[i]].depth = T[x[i]].depth + 1;
        tree_el.insert(y[i]);
      } else if (tree_el.find(y[i]) != tree_el.end()) {
        T[x[i]].par = y[i];
        T[x[i]].depth = T[y[i]].depth + 1;
        tree_el.insert(x[i]);
      } else continue;
      x.erase(x.begin() + i);
      y.erase(y.begin() + i);
    }
  }


  // 2. クエリ処理
  int ans, a, b;
  cin >> Q;
  rep(i, Q) {
    ans = 0;
    // 入力
    cin >> a >> b;
    a--;
    b--;
    // 遡る
    if (T[a].depth < T[b].depth) swap(a, b); // -> "T[a].depth >= T[b].depth" equals true
    while (T[a].depth != T[b].depth) {
      ans += 1;
      a = T[a].par;
    }
    // 同じノードまで遡り続ける
    while (a != b) {
      ans += 2;
      a = T[a].par;
      b = T[b].par;
    }
    // 出力
    cout << ans + 1 << endl;
  }
  return 0;
}
