#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string hello = "Hello";
  vector test_vector = {1, 2, 3};
  // size_t is a special type!
  // It's usually used for the size of data structures
  size_t string_size = hello.size();
  size_t vector_size = test_vector.size();

  const int x = 5;
  // x = 7; // not allowed!
  typedef int number;
  number my_number = 7;

  typedef unsigned int uint;
  uint my_unsigned_int = 10;

  typedef long long looooong;
  looooong my_looong = 25;

  // == AUTO ==
  auto automatically_a_string = "hello";
  auto automatically_an_int = 100;

  // == TYPE COERCION AND CASTING ==
  
  int test = 500;
  long long_test = test; // These aren't the same types. test is being "coerced" into a long
  
  // == HORRIFYING CODE ==
  unsigned int one = 1;
  int negative_one = -1;

  if (one > negative_one) {
    cout << "One is greater than negative one!" << endl;
  }
  else {
    cout << "One is less than negative one!" << endl;
  }
}