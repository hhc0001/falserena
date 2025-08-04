#include <bits/stdc++.h>
using namespace std;

struct abstract {
  string a;
  int b;
  
  virtual ~abstract() = default;
  virtual void placeHolder() = 0;
};

struct derived : abstract {
  int c;
  
  void placeHolder() override {
  }
};

derived a;

int main() {
  a.a = "11111", a.c = 114514;
  abstract* b = &a;
  cout << dynamic_cast<derived*>(b) -> c << '\n';
  return 0;
}
