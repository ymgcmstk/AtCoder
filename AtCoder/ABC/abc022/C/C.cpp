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
#define BN 1000000007
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

struct Edge {
  int to, cost;
  Edge (int to, int cost) : to(to), cost(cost) {}
};

typedef vector<Edge> Edges;

int main() {
  int N, M;
  cin >> N >> M;
  int H[N][N];
  int H0[N];
  fill(H0, H0+N, -1);
  rep(i, N) {
    fill(H[i], H[i]+N, BN);
    H[i][i] = 0;
  }

  Edges Es;
  int u, v, l;
  rep(i, M) {
    cin >> u >> v >> l;
    u--;
    v--;
    if (u == 0) H0[v] = l;
    else if (v == 0) H0[u] = l;
    else {
      H[u][v] = l;
      H[v][u] = l;
    }
  }
  int temp;
  rep(i, N) rep(j, N) rep(k, N) {
    temp = H[j][i] + H[i][k];
    if (temp < 0) continue;
    H[j][k] = min(H[j][k],  temp);
  }
  int cur_min = BN;
  rep(i, N) repd(j, i+1, N) {
    if (H0[i] < 0) continue;
    if (H0[j] < 0) continue;
    if (H[i][j] < 0) continue;
    temp = H0[i] + H0[j] + H[i][j];
    if (temp <= 0) continue;
    cur_min = min(cur_min, temp);
  }
  if (cur_min == BN) cur_min = -1;
  cout << cur_min << endl;
  return 0;
}
