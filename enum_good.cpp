#include <iostream>
using namespace std;

// define an enum, has a fixed set of values
enum class Team { // have to use "enum class" otherwise becomes an unscoped enum
  red,
  blue,
  green
};

void print_winning_team(Team team_name) {
  // you can use and compare those values
  if (team_name == Team::red)
      cout << "RED TEAM WINS!!" << endl;

  if (team_name == Team::blue)
      cout << "BLUE TEAM WINS!!" << endl;

  if (team_name == Team::green)
      cout << "GREEN TEAM WINS!!" << endl;
}

int main() {
  // you can use those values
  // the compiler will complain if you use them wrong
  print_winning_team(Team::red);
}