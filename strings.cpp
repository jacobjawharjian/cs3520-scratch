#include <iostream>
#include <string>
using namespace std;

int main() {
  string hello = "Hello, ";
  string world = "world!";
  string hello_world; // empty string: not undefined

  cout << hello << world << endl;
  cout << hello + hello_world + world << endl;

  hello += world;

  cout << hello.at(0) << endl; // potential exception

  string::size_type n = hello.size();
  cout << n << endl;

  cout << hello.empty() << endl;
  
  // == ADVANCED STRING STUFF ==
  
  size_t pos = hello.find("ll");
  if (pos != hello.npos) {
    cout << "Found \"ll\" at: " << pos << endl;
  }

  // substring asks for position and number of characters
  // cuts the substring short if the end is outside the bounds of the string
  cout << "Hello substring: " << hello.substr(2, 1) << endl; // l

  hello.erase(0, 1); // potential range exception
  cout << hello << endl; // ello, world!

  hello.insert(0, "X"); // potential range exception
  cout << hello << endl; // Xello, world!
}