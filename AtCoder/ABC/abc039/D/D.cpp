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

typedef vector<bool> vb;
typedef vector<vb> vvb;

const int d_x[] = {0, 1, 0, -1, 0, 1, 1, -1, -1};
const int d_y[] = {1, 0, -1, 0, 0, 1, -1, 1, -1};

bool WHITE = false;
bool BLACK = true;

bool reconvert(vvb a, vvb b) {
  repd(i, 1, a.size() - 1) {
    repd(j, 1, a[i].size() - 1) {
      bool temp = WHITE;
      rep(k, 9) {
        if (a[i+d_x[k]][j+d_y[k]] == BLACK) {
          temp = BLACK;
          break;
        }
      }
      if (temp != b[i][j]) return false;
    }
  }
  return true;
}

int main() {
  int H, W;
  cin >> H >> W;
  vvb org_vvb;
  vvb ans_vvb;
  vb all_b, all_w,buf_vb, buf_vb2;
  rep(i, W+2) all_b.push_back(BLACK);
  rep(i, W+2) all_w.push_back(WHITE);
  org_vvb.push_back(all_b);
  ans_vvb.push_back(all_w);
  string buf_str;
  rep(i, H) {
    cin >> buf_str;
    buf_vb = vb(0);
    buf_vb2 = vb(0);
    buf_vb.push_back(BLACK);
    buf_vb2.push_back(WHITE);
    rep(j, W) {
      if (buf_str[j] == '#') buf_vb.push_back(BLACK);
      else buf_vb.push_back(WHITE);
      buf_vb2.push_back(WHITE);
    }
    buf_vb.push_back(BLACK);
    buf_vb2.push_back(WHITE);
    org_vvb.push_back(buf_vb);
    ans_vvb.push_back(buf_vb2);
  }
  org_vvb.push_back(all_b);
  ans_vvb.push_back(all_w);
  repd(i, 1, H+1) {
    repd(j, 1, W+1) {
      bool temp = BLACK;
      rep(k, 9) {
        if (org_vvb[i+d_x[k]][j+d_y[k]] == WHITE) {
          temp = WHITE;
          break;
        }
      }
      ans_vvb[i][j] = temp;
    }
  }
  if (debug_mode) rep(i, H+2) show_vec(org_vvb[i]);
  if (debug_mode) rep(i, H+2) show_vec(ans_vvb[i]);
  if (reconvert(ans_vvb, org_vvb)) {
    cout << "possible" << endl;
    repd(i, 1, H+1) {
      repd(j, 1, W+1) {
        if (ans_vvb[i][j] == BLACK) cout << '#';
        else  cout << '.';
      }
      cout << endl;
    }
  } else cout << "impossible" << endl;
  return 0;
}
