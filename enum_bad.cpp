#include <iostream>
using namespace std;

void print_winning_team(string team_name) {
  if (team_name == "red")
      cout << "RED TEAM WINS!!" << endl;

  if (team_name == "blu") // "blue" is misspelled (blue) --> when the code is running, the if statement would not trigger
      cout << "BLUE TEAM WINS!!" << endl;

  if (team_name == "green")
      cout << "GREEN TEAM WINS!!" << endl;
}

int main() {
  print_winning_team("red");
}