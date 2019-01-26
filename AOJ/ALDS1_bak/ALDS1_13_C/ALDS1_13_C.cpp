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

typedef vector<vector<int> > vvi;

typedef pair<string, int> si;

string convert_string(vvi V) {
  string ans = "";
  rep(i, 3) rep(j, 3) ans += V[i][j];
  return ans;
}

const int DEPTH = 4;

class PUZZLE {
public:
  string state;
  int turn;
  PUZZLE () {}
  PUZZLE (int turn, string state) : turn(turn), state(state) {}
  int estimate(){
    int ans = this->turn;
    rep(i, DEPTH * DEPTH) {
      int cur_0 = state[i] - '0';
      int cur_a = state[i] - 'a' + 10;
      int x = i % DEPTH;
      int y = i / DEPTH;
      if (cur_0 < 10 && cur_0 > 0) ans += abs((cur_0 - 1) % DEPTH - x) + abs((cur_0 - 1) / DEPTH - y);
      else if (cur_a >= 10 && cur_a <= 16) ans += abs((cur_a - 1) % DEPTH - x) + abs((cur_a - 1) / DEPTH - y);
      else ans += abs(DEPTH - 1 - x) + abs(DEPTH - 1 - y);
    }
    return ans;
  }
  bool operator < (const PUZZLE &P) const {
    // if (P.estimate() > this->estimate()) return true;
    if (P.state > this->state) return true;
    else return false;
  }
};


void add_queue(priority_queue<pair<int, PUZZLE> > &Q, set<string> &generated) {
  string cur_str = Q.top().second.state;
  int zero_ind = cur_str.find("0");
  string new_str;
  if (zero_ind % DEPTH != 0) {
    new_str = cur_str;
    swap(new_str[zero_ind], new_str[zero_ind-1]);
    if (generated.find(new_str) == generated.end()) {
      PUZZLE puzzle = PUZZLE(Q.top().second.turn+1, new_str);
      Q.push(make_pair(puzzle.estimate(), puzzle));
      generated.insert(new_str);
    }
  }
  if (zero_ind % DEPTH != DEPTH-1) {
    new_str = cur_str;
    swap(new_str[zero_ind], new_str[zero_ind+1]);
    if (generated.find(new_str) == generated.end()) {
      PUZZLE puzzle = PUZZLE(Q.top().second.turn+1, new_str);
      Q.push(make_pair(puzzle.estimate(), puzzle));
      generated.insert(new_str);
    }
  }
  if (zero_ind < DEPTH * (DEPTH-1)) {
    new_str = cur_str;
    swap(new_str[zero_ind], new_str[zero_ind+DEPTH]);
    if (generated.find(new_str) == generated.end()) {
      PUZZLE puzzle = PUZZLE(Q.top().second.turn+1, new_str);
      Q.push(make_pair(puzzle.estimate(), puzzle));
      generated.insert(new_str);
    }
  }
  if (zero_ind >= DEPTH) {
    new_str = cur_str;
    swap(new_str[zero_ind], new_str[zero_ind-DEPTH]);
    if (generated.find(new_str) == generated.end()) {
      PUZZLE puzzle = PUZZLE(Q.top().second.turn+1, new_str);
      Q.push(make_pair(puzzle.estimate(), puzzle));
      generated.insert(new_str);
    }
  }
  Q.pop();
}

int main() {
  // vvi MAP(3);
  int temp;
  string initial_state;
  rep(i, DEPTH*DEPTH) {
    cin >> temp;
    if (temp < 10) initial_state += char(temp + '0');
    else initial_state += char(temp + 'a' - 11);
  }
  set<string> generated;
  priority_queue<pair<int, PUZZLE> > Q;
  PUZZLE initial_puzzle = PUZZLE(0, initial_state);
  Q.push(make_pair(initial_puzzle.estimate(), initial_puzzle));
  generated.insert(initial_state);
  while (Q.top().second.state != "123456789abcdef0") add_queue(Q, generated);
  cout << Q.top().second.state << endl;
  return 0;
}
