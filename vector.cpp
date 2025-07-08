#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_vector(vector<int> to_print) {
  cout << "------" << endl;
  for (auto val : to_print) {
    cout << val << endl;
  }
  cout << "------" << endl;
}

int main() {
  vector<int> v1; // initialized empty
  vector<int> pre_initialized = {1, 2, 4, 5};
  vector<int> also_pre_initialized(5, 100);

  // for (auto val: also_pre_initialized) {
  // cout << val << endl;
  // }

  v1.push_back(0);
  v1.push_back(1);
  v1.push_back(2);
  cout << "v1 size: " << v1.size() << endl;

  cout << "Last value of v1: " << v1.back() << endl;
  v1.pop_back(); // remove back, undefined on empty

  v1.resize(20, -1);        // "default insertion"
  cout << v1[7] << endl;    // gets the 8th element, unchecked
  cout << v1.at(7) << endl; // gets the 8th element, throws exception

  v1.resize(2);
  print_vector(v1);

  v1.insert(v1.begin() + 1, 5);
  print_vector(v1);

  v1.erase(v1.begin() + 2);
  print_vector(v1);

  // == VECTOR OF VECTORS

  vector<vector<int>> two_dimension_vec(5, vector<int>(5, 0));
  vector<vector<int>> also_two_dimension_vec = {
    {3, 3, 3},
    {3, 3, 3},
    {3, 3, 3},
  };

  cout << also_two_dimension_vec.at(1).at(0) << endl;
}