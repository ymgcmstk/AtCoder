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

class Node {
public:
  Node* left;
  Node* right;
  Node* parent;
  int key;
  Node() {}
  Node(int key) : key(key) {}
  Node(int key, Node* par) : key(key) {
    this->parent = par;
  }
};

int preplace = 0;

void postorderization(vector<int> &preorder, vector<int> &inorder, vector<int> &postorder, int left, int right) {
  if (left == right) return;
  int eol = -1;
  repd(i, left, right) if (inorder[i] == preorder[preplace]) {
    eol = i;
    break;
  }
  int cur = preplace;
  preplace++;
  postorderization(preorder, inorder, postorder, left, eol);
  postorderization(preorder, inorder, postorder, eol+1, right);
  postorder.push_back(preorder[cur]);
}

int main() {
  int N;
  cin >> N;
  vector<int> preorder(N);
  vector<int> inorder(N);
  rep(i, N) cin >> preorder[i];
  rep(i, N) cin >> inorder[i];
  vector<int> postorder;
  // rep(i, N) postorder[i] = inorder[i];
  postorderization(preorder, inorder, postorder, 0, N);
  rep(i, N-1) cout << postorder[i] << ' ';
  cout << postorder[N-1] << endl;
  return 0;
}
