#include <iostream>
using namespace std;
struct Edge1 {
  int a, b;
  Edge1(int p, int q) : a(p), b(q) {}
};
struct Edge2 {
  int a, b;
  Edge2(int p, int q) {
    a = p;
    b = q;
  }
};

struct Edge2 {
  int a, b;
  Edge2(int p, int q) {
    a = p;
    b = q;
  }
};

int main() {
  Edge1 p = Edge1(1, 2);
  cout << "Edge1: " << p.a << ", " << p.b << endl;
  Edge2 q = Edge2(1, 2);
  cout << "Edge2: " << q.a << ", " << q.b << endl;
  return 0;
}
