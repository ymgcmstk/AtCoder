#include <iostream>
using namespace std;

class Edge1 {
protected:
  int a;
  int b;
public:
  Edge1() {
  }
  Edge1(int p, int q) {
    a = p;
    b = q;
  }
};

class Edge2 : public Edge1 {
public:
  Edge2() {
  }
  Edge2(int p, int q) {
    a = p * p;
    b = q * q;
  }
  void print() {
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
  }
};


int main() {
  Edge1 p = Edge1(1, 2);
  // cout << "Edge1: " << p.a << ", " << p.b << endl;
  // cout << "Edge1: " << p.a << ", " << p.b << endl;
  Edge2 q = Edge2(1, 2);
  q.print();
  Edge2* r = new Edge2(1, 2);
  r->print();

  return 0;
}
