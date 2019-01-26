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

typedef pair<int, int> pii;

int main() {
  int N;
  cin >> N;
  int x, y;
  vector<pii> vpii;
  string S;
  rep(i, N) {
    // cin >> x >> y;
    cin >> S;
    x = stoi(S.substr(0, 4));
    y = stoi(S.substr(5, 4));
    vpii.push_back(make_pair(x / 5 * 5, (y + 4) / 5 * 5));
    if (vpii[i].second % 100 == 60) vpii[i].second += 40;
  }
  sort(vpii.begin(), vpii.end());
  int i = 0;
  while (vpii.size() - 1 > i) {
    if (vpii[i].second >= vpii[i+1].first) {
      vpii[i].second = max(vpii[i+1].second, vpii[i].second);
      vpii.erase(vpii.begin() + i + 1);
    } else i++;
  }
  string temp;
  rep(i, vpii.size()) {
    temp = to_string(vpii[i].first);
    rep(j, 4-temp.size()) cout << '0';
    cout << temp;
    cout << '-';
    temp = to_string(vpii[i].second);
    // cout << temp.size() << 'a' << endl;
    rep(j, 4-temp.size()) cout << '0';
    cout << temp;
    cout << endl;
  }
  return 0;
}
