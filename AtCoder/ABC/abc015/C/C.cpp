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
#define rep(i,n) repd(i,0,n)
#define LL long long

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

int main() {
  int N, M;
  cin >> N >> M;
  int temp;
  set<int> setpool;
  set<int> temppool;
  setpool.insert(0);
  rep(i, N) {
    rep(j, M) {
      cin >> temp;
      for (set<int>::iterator itt = setpool.begin(); itt != setpool.end(); itt++) {
        temppool.insert(*itt ^ temp);
      }
    }
    setpool.clear();
    for (set<int>::iterator itt = temppool.begin(); itt != temppool.end(); itt++) {
      setpool.insert(*itt);
    }
    temppool.clear();
  }
  if (setpool.find(0) == setpool.end()) {
    cout << "Nothing" << endl;
  } else {
    cout << "Found" << endl;
  }
  return 0;
}