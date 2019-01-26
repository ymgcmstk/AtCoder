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

vector<int> A;
vector<int> B;

template <typename T> vector<T> merge(vector<T> b, int left, int right) {
  int len = right - left;
  if (len < 2) return b;
  int mid = (right + left) / 2;
  b = merge(b, left, mid);
  b = merge(b, mid, right);
  int temp1, temp2;
  temp1 = left;
  temp2 = mid;
  T temp_vec[len];
  rep(i, len) {
    if (mid <= temp1) {
      temp_vec[i] = b[temp2];
      temp2++;
    } else if (right <= temp2) {
      temp_vec[i] = b[temp1];
      temp1++;
    } else if (b[temp1] < b[temp2]) {
      temp_vec[i] = b[temp1];
      temp1++;
    } else {
      temp_vec[i] = b[temp2];
      temp2++;
    }
  }
  rep(i, len) {
    b[i+left] = temp_vec[i];
  }
  return b;
}

int main() {
  int N = 20;
  rep(i, N)A.push_back(i);
  random_shuffle(A.begin(), A.end());
  rep(i, N)B.push_back(A[i]);
  // --------

  B = merge(B, 0, B.size());

  // --------
  sort(A.begin(), A.end());
  bool flg = true;
  rep(i, N) {
    if (A[i] != B[i]) {
      cout << "error" << endl;
      rep(j, N) cout << B[j] << endl;
      flg = false;
      break;
    }
  }
  if (flg) cout << "success" << endl;
  return 0;
}
