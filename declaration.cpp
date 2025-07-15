#include <iostream>
using namespace std;

// This class could / should be in a header file
class ClassName {
  int test_function1(int input);
  void test_function2();
public:
  void run_tests(int input);
};

// And these definitions could / should be in an implementation file
int ClassName::test_function1(int input) {
  return input * 2;
}

void ClassName::test_function2() {
  cout << "Test2" << endl;
}

void ClassName::run_tests(int input) {
  cout << test_function1(input) << endl;
  test_function2();
}

int main() {
  ClassName foo;
  foo.run_tests(5);
}