#include <iostream>
using namespace std;

class BoxedInt {
  int internal_int;

public:
  BoxedInt(int _internal_int) : internal_int(_internal_int) {};
  BoxedInt() : internal_int(0) {};

  // Simple operators, they just return a BoxedInt value
  // nothing crazy yet...
  BoxedInt operator+(int other) const;
  BoxedInt operator+(const BoxedInt &other) const;

  // These operators mutate the BoxedInt
  // so they have to return a reference
  // using the special syntax "return *this"
  BoxedInt &operator-=(const BoxedInt &other);
  BoxedInt &operator+=(const BoxedInt &other);

  // These operators return internal data
  // so we need a const and non-const version
  // The non-const version returns a reference
  int operator[](int i) const;
  int &operator[](int i);

  // Prefix operators modify then return a reference. 
  // Postfix operators copy, modify, then return the old value
  // Prefix: ++x
  // Postfix: x++
  BoxedInt & operator++();
  // This postfix operator has (int) as a dummy parameter
  BoxedInt operator++(int);

  /**
   * These operators have a left hand side that isn't controlled by BoxedInt
   * What do I mean by that?
   * imagine the following code:
   * int i; BoxedInt b;
   * cout << (i + b);
   * The left hand is an integer,
   * but the definition of an integer isn't controlled by BoxedInt
   * Similarly, with cout << b
   * the definition of cout isn't controlled by BoxedInt
   *
   * So, to get around this, you define these operators by making them
   * friend, non-member functions with two inputs
   */
  friend BoxedInt operator+(int other, BoxedInt boxed_int);
  // ostream is the parent class of cout.
  // The following operator lets us pass BoxedInt to cout
  friend ostream &operator<<(ostream &os, const BoxedInt &b);

  // You can set up implicit conversion to a boolean with "operator bool()"
  // This allows you to do things like:
  // BoxedInt my_boxed_int(5)
  // if (my_boxed_int)...
  operator bool() const;
};

BoxedInt BoxedInt::operator+(const BoxedInt &other) const {
  int new_value = internal_int + other.internal_int;
  BoxedInt new_boxed_int = BoxedInt(new_value);
  return new_boxed_int;
}

BoxedInt BoxedInt::operator+(int other) const {
  int new_value = internal_int + other;
  BoxedInt new_boxed_int = BoxedInt(new_value);
  return new_boxed_int;
}

BoxedInt &BoxedInt::operator-=(const BoxedInt &other) {
  int new_value = internal_int - other.internal_int;
  internal_int = new_value;
  return *this;
}

BoxedInt &BoxedInt::operator+=(const BoxedInt &other) {
  int new_value = internal_int + other.internal_int;
  internal_int = new_value;
  return *this;
}

ostream &operator<<(ostream &os, const BoxedInt &b) {
  os << b.internal_int;
  return os;
}

BoxedInt operator+(int other, BoxedInt boxed_int) {
  int new_value = other + boxed_int.internal_int;
  BoxedInt new_boxed_int = BoxedInt(new_value);
  return new_boxed_int;
}

int BoxedInt::operator[](int i) const {
  // Since there's only one element
  // let's make this operator only accept 0
  // e.g. boxed_int[0]
  if (i == 0) {
    return internal_int;
  } else {
    // We can cause an error if anything other than 0 is requested.
    throw out_of_range("There's only one element in here.");
  }
}

int &BoxedInt::operator[](int i) {
  // Since there's only one element
  // let's make this operator only accept 0
  // e.g. boxed_int[0]
  if (i == 0) {
    return internal_int;
  } else {
    // We can cause an error if anything other than 0 is requested.
    throw out_of_range("There's only one element in here.");
  }
}

BoxedInt & BoxedInt::operator++() {
  internal_int = internal_int + 1;
  return *this;
}

BoxedInt BoxedInt::operator++(int) {
  BoxedInt copied_boxed_int = BoxedInt(internal_int);
  internal_int = internal_int + 1;
  return copied_boxed_int;
}

BoxedInt::operator bool() const {
  return internal_int != 0;
}

int main() {
  BoxedInt boxed_int(5);
  BoxedInt other(7);


  cout << boxed_int << endl;
  cout << boxed_int[0] << endl;

  boxed_int++;
  cout << boxed_int << endl;
  ++boxed_int;
  cout << boxed_int << endl;

  cout << (BoxedInt(1) ? "true" : "false") << endl;
  cout << (BoxedInt(0) ? "true" : "false") << endl;
}