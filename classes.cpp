#include <iostream>
using namespace std;

class Date { // name of class
  // member variables, by default private
  int month;
  int day;
  int year;

public:
  // a function inside a class can use the class' member variables
  // const implies the class object will not change
  void print() const { 
    cout << month << "/" << day << "/" << year << endl; 
  }

  // a default constructor is called when you default initialize a class
  Date() {
    month = 1;
    day = 1;
    year = 1970;
    cout << "Default constructing date:" << endl;
    print();
  }

  // you can have more complex constructors
  Date(int _month, int _day, int _year)
  // the "initializer list" allows you to set basic variables
      : month(_month), day(_day), year(_year) {
    cout << "Constructing date:" << endl;
    print();
  }

  // the destructor is called when the object is deleted
  ~Date() {
    cout << "Destructing date:" << endl;
    print();
  }
};

void test_function(Date date) { }

int main() {
  // this date will use the default constructor
  Date default_date;

  // various ways to create an object
  // Date d1 = {3, 14, 2025};
  // Date d2{6, 28, 2025};
  // Date d3(5, 4, 2025);

  // using a public member function from a class
  // d1.print();

  // you can construct an object right into a function or similar
  // test_function({});
  // test_function({10, 10, 2010});
  // test_function(Date(5, 5, 2005));
}