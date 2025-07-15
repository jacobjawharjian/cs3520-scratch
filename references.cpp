#include <iostream>
#include <string>
#include <vector>
using namespace std;

void takes_a_reference(int &reference) {
  // reasonable
  cout << reference << endl;
}

// int & returns_a_reference() {
  // Don't do this!
  // int reference;
  // return reference;
// }

class Test {
  int private_int = 10;
public:
  int &get_private_int() { return private_int; }
  void print_private_int() { cout << private_int << endl;}
  Test() : private_int(0) {}
  Test(int _private_int) : private_int(_private_int) {}
};

int main() {
  Test test;
  test.print_private_int();

  int & internal_reference = test.get_private_int();
  internal_reference = 77;
  test.print_private_int();

  test.get_private_int() = 99;
  test.print_private_int();

  cout << "--------------" << endl;
  vector<Test> tests = {{1}, {2}, {3}};
  for (auto & test_item : tests) {
    test_item.print_private_int();
  }
  cout << "--------------" << endl;
  for (auto & test_item : tests) {
    test_item.get_private_int()++;
  }
  for (auto & test_item : tests) {
    test_item.print_private_int();
  }
}