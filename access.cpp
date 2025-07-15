#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Parent {
  // Visible only to parent
  // Not even children!
private:
  int private_invisible;
protected:
  int protected_visible_to_parent_and_children;
public:
  int public_visible_to_everyone;

  friend class FriendlyClass;
  friend void friendly_function(Parent p);
};

class PubliclyInheritingChild : public Parent {
  void test() {
    // Everything works as you'd expect
    // Cannot see private_invisible
    // cout << private_invisible; // ERROR!
    // Can see protected_visible_to_parent_and_children
    cout << protected_visible_to_parent_and_children;
    // Can see public_visible_to_everyone
    cout << public_visible_to_everyone;
  }
};

class PrivatelyInheritingChild : private Parent {
  void test() {
    // Everything is now private
    // Cannot see private_invisible
    // (it's still invisible to me)
   // cout << private_invisible; // ERROR!
    // Can see protected_visible_to_parent_and_children
    // (but now it's private, so my children can't see it)
    cout << protected_visible_to_parent_and_children;
    // Can see public_visible_to_everyone
    // (but now it's private, so others can't see it)
    cout << public_visible_to_everyone;
  }
};

class FriendlyClass {
  Parent p;
  void test() {
    // Friend class can use any vars!
    cout 
      << p.private_invisible 
      << p.protected_visible_to_parent_and_children 
      << p.public_visible_to_everyone 
      << endl;
  }
};

void friendly_function(Parent p) {
  // Friend function can use any vars!
  cout 
    << p.private_invisible 
    << p.protected_visible_to_parent_and_children 
    << p.public_visible_to_everyone 
    << endl;
}

int main() {
  PubliclyInheritingChild publicly_inheriting_child;
  PrivatelyInheritingChild privately_inheriting_child;

  cout << publicly_inheriting_child.public_visible_to_everyone << endl;
  // cout << privately_inheriting_child.public_visible_to_everyone << endl; // ERROR!
}