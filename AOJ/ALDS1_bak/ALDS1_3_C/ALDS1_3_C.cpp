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

class Node {
public:
  Node* prev;
  Node* next;
  LL key;
  Node() {}
  Node(LL key, Node* p, Node* n): key(key) {
    this->prev = p;
    this->next = n;
  }
};

int main() {
  LL N, key;
  string S;
  cin >> N;
  Node* nil = new Node();
  nil->prev = nil;
  nil->next = nil;
  nil->key = -1;
  Node* temp_node;
  rep(i, N) {
    cin >> S;
    if (S == "insert") {
      cin >> key;
      temp_node = new Node(key, nil->prev, nil);
      temp_node->prev->next = temp_node;
      nil->prev = temp_node;
    } else if (S == "delete") {
      cin >> key;
      temp_node = nil->prev;
      bool cont_flg = false;
      while (temp_node->key != key) {
        temp_node = temp_node->prev;
        if (temp_node == nil) {
          cont_flg = true;
          break;
          // cout << "ERROR" << endl;
        }
      }
      if (cont_flg) continue;
      temp_node->next->prev = temp_node->prev;
      temp_node->prev->next = temp_node->next;
      delete temp_node;
    } else if (S == "deleteLast") {
      temp_node = nil->next;
      nil->next = temp_node->next;
      nil->next->prev = nil;
      delete temp_node;
    } else if (S == "deleteFirst") {
      temp_node = nil->prev;
      nil->prev = temp_node->prev;
      nil->prev->next = nil;
      delete temp_node;
    } else {
      cout << "ERROR" << endl;
      return 0;
    }
  }
  temp_node = nil->prev;
  while (true) {
    if (temp_node->prev != nil) cout << temp_node->key << ' ';
    else {
      cout << temp_node->key << endl;
      return 0;
    }
    temp_node = temp_node->prev;
  }
}
