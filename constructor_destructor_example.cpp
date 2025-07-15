#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Parent {
  int foo;

public:
  // Called implicitly by child!
  Parent() {}
  // Must be called explicitly
  Parent(int _foo) 
    : foo(_foo) {}
};

class Child : public Parent {
  // Will call Parent()
  Child() {}
  // Will call Parent(_foo)
  Child(int _foo) 
    : Parent(_foo) {}
  // Will call Parent also
  Child(string _bar) 
    : Parent(100) {}
};

int main() {
}