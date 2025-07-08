#include <iostream>
#include <string>
#include <vector>
using namespace std;

// a function is a small/large function that can be reused
// returns a value to the code that is callling the function
//

int triple(int input) {
  return input * 3;
}
void print(string input) {
  cout 
    << "Printing string: " 
    << input 
    << endl;
}
void print(int input) {
  cout 
    << "Printing int: " 
    << input 
    << endl;
}
void print(double input = 0.0) {
  cout 
    << "Printing double, possible default: " 
    << input 
    << endl;
}
void mutate_triple(int & input) {
  input = input * 3;
}
void print_vector(const vector<int> & input) {
  for (auto val : input) {
    cout << val << " ";
  }
  cout << endl;
}

int main() {
  cout << triple(10) << endl;
  print("Hello");
  print(10);
  print();

  cout << "==========" << endl;
  int to_be_tripled = 5;
  print(to_be_tripled);
  mutate_triple(to_be_tripled);
  print(to_be_tripled);
}