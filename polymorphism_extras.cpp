#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
public:
  // We made this function pure virtual by adding "= 0"
  // A class with a pure virtual function cannot be instantiated!
  virtual void make_noise() const = 0;
};

class Dog : public Animal {
public:
  // Signature must be exact!
  // Because the parent function is const
  // this must be const as well
  void make_noise() const override {
    cout << "Woof" << endl;
  }
};

class Bird : public Animal {
public:
  void make_noise() const override {
    cout << "Chirp" << endl;
  }
};

class Parent {
  virtual void foo() {}
};

class Child : public Parent {};

void cast_test(Parent & parent_or_child) {
  // Faster, but less safe
  // You might think it worked, but it's undefined behavior
  Child c1 = static_cast<Child &>(parent_or_child);
  // Will throw a catchable error if it fails
  Child c2 = dynamic_cast<Child &>(parent_or_child);
}

int main() {
  Dog dog1;
  dog1.make_noise();

  Child c;
  cast_test(c);
}