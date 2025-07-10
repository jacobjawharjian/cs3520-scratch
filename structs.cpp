#include <iostream>
#include <vector>
using namespace std;

// structs hold a variety of variables (member variables)
struct Date { // name of new type
  // member variables
  const int month;
  const int day;
  const int year;
};

void print_date(const Date date) {
  // you can access member variable using .
  cout 
    << date.month 
    << "/" 
    << date.day 
    << "/" 
    << date.year 
    << endl; 
}

int main() {
  // creating a struct. Order matters!
  Date d1 = {3, 14, 2025};
  // designated initializers, order still matters!
  Date d2 = {.month = 6, .day = 28, .year = 2025};

  print_date(d1);
  print_date(d2);
  print_date({.month = 11, .day = 11, .year = 2011});

  // you can use your struct as a type.
  vector<Date> dates1;
  // you can use the initializer
  vector<Date> dates2 = {
    {1, 1, 2001},
    {3, 3, 2003},
  };
  // you can use structs like other variables
  dates1.push_back(d1);
  // you can use the initializer inside functions
  dates1.push_back({9, 24, 1998});
}