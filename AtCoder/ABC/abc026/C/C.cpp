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

struct Node {
  int upper, bottom, right, salary, depth;
  Node (int upper, int par_depth) : upper(upper), depth(par_depth + 1) {
    bottom = -1;
    right  = -1;
    salary = 1;
  }
  Node () {
    upper  = -1;
    bottom = -1;
    right  = -1;
    salary = 1;
    depth = 0;
  }
};

typedef vector<Node> VN;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void display(VN vn) {
  rep(i, vn.size()) cout << "id: " << i << ", parent: " << vn[i].upper << ", right: " << vn[i].right << ", bottom: " << vn[i].bottom << ", depth: " << vn[i].depth  << ", salary: " << vn[i].salary << endl;
}

int main() {
  bool debug_mode = false;
  int N;
  cin >> N;
  VN nodes;
  nodes.push_back(Node());
  int temp;
  // priority_queue<pii, vpii, greater<pii> > pq;
  priority_queue<pii, vpii> pq;
  pq.push(make_pair(nodes[0].depth, 0));
  repd(i, 1, N) {
    cin >> temp;
    temp -= 1;
    nodes.push_back(Node(temp, nodes[temp].depth));
    if (nodes[temp].bottom == -1) {
      nodes[temp].bottom = i;
    } else {
      int cur_left = nodes[temp].bottom;
      while (nodes[cur_left].right >= 0) cur_left = nodes[cur_left].right;
      nodes[cur_left].right = i;
    }
    pq.push(make_pair(nodes[i].depth, i));
  }

  int child_min, child_max;

  while (pq.size() > 0) {
    pii cur_pair = pq.top();
    pq.pop();
    if (debug_mode) cout << cur_pair.second << ", ";
    nodes[cur_pair.second].salary = 1;
    if (nodes[cur_pair.second].bottom >= 0) {
      temp = nodes[cur_pair.second].bottom;
      child_min = nodes[temp].salary;
      child_max = nodes[temp].salary;
      while (nodes[temp].right >= 0) {
        temp = nodes[temp].right;
        child_min = min(child_min, nodes[temp].salary);
        child_max = max(child_max, nodes[temp].salary);
      }
      nodes[cur_pair.second].salary += child_min + child_max;
    }
  }
  if (debug_mode) {
    cout << endl;
    display(nodes);
  }
  cout << nodes[0].salary << endl;
  return 0;
}
