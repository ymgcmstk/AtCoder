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

class Node {
public:
  Node *prev, *next;
  int val;
  Node() {}
  Node(Node* _prev, int _val) {
    this->val = _val;
    this->prev = _prev;
  }
};

void show(Node* base) {
  Node* cur_node = base->next;
  while(cur_node->next != base) {
    cout << cur_node->val << ' ';
    cur_node = cur_node->next;
  }
  cout << cur_node->val << endl;
}

int main() {
  int N;
  cin >> N;
  vector<int> list(N);
  Node* base = new Node();
  Node* cur_node;
  int cur_val;
  base->val = -1;
  cur_node = base;
  rep(i, N) {
    cin >> cur_val;
    cur_node = new Node(cur_node, cur_val);
    cur_node->prev->next = cur_node;
  }
  cur_node->next = base;
  Node* next_node = base->next;
  Node* loop_node;
  rep(i, N) {
    cur_node = next_node;
    next_node = next_node->next;
    loop_node = base;
    rep(j, i) {
      loop_node = loop_node->next;
      if (loop_node->val > cur_node->val) {
        cur_node->prev->next = cur_node->next;
        cur_node->next->prev = cur_node->prev;
        cur_node->prev = loop_node->prev;
        cur_node->next = loop_node;
        loop_node->prev->next = cur_node;
        loop_node->prev = cur_node;
        break;
      }
    }
    show(base);
  }
  return 0;
}
