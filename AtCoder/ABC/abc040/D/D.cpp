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

class UF {
public:
  vector<int> par, sz;
  UF(int n) {
    par.resize(n);
    sz.resize(n,1);
    rep(i,n)par[i]=i;
  }
  int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    sz[x]+=sz[y];
    par[y]=x;
  }
};

int main() {
  int N, M, Q;
  cin >> N >> M;
  int a[M], b[M], y[M];
  int temp_a, temp_b, temp_y;
  int par_b[N], n_c_b[N];
  rep(i, N) {
    par_b[i] = -1;
    n_c_b[i] = 1;
  }
  vector< pair< int, pair<int, int> > > b_vec;
  rep(i, M) {
    cin >> temp_a >> temp_b >> temp_y;
    a[i] = temp_a;
    b[i] = temp_b;
    y[i] = temp_y;
    b_vec.push_back(make_pair(-temp_y, make_pair(temp_a, temp_b)));
  }
  b_vec.push_back(make_pair(1, make_pair(1, 1)));
  cin >> Q;
  int v[Q], w[Q], h_ans[Q];
  vector< pair< int, pair< int, int > > > human;
  rep(i, Q) {
    cin >> v[i] >> w[i];
    human.push_back(make_pair(-w[i], make_pair(i, v[i])));
  }
  sort(b_vec.begin(), b_vec.end());
  sort(human.begin(), human.end());
  int cur_y, t_a, t_b;
  cur_y = MOD;
  int cur_h_ind = 0;
  rep(i, M+1) {
    cur_y = -b_vec[i].first;
    while (-human[cur_h_ind].first > cur_y) {
      if (par_b[human[cur_h_ind].second.second] == -1) h_ans[human[cur_h_ind].second.first] = n_c_b[human[cur_h_ind].second.second];
      else h_ans[human[cur_h_ind].second.first] = n_c_b[par_b[human[cur_h_ind].second.second]];
      cur_h_ind++;
    }
    if (i == M) break;
    t_a = b_vec[i].second.first;
    t_b = b_vec[i].second.second;
    // TODO

  }
  return 0;
}
