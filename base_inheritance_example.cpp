#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
protected:
  int num_legs;
public:
  void eat() {}
};

class Dog : public Animal {
  // has num_legs and eat()
public:
  void bark() {}
};

class Bird : public Animal {
  // has num_legs and eat()
public:
  void fly() {}
};

int main() {
  Animal animal;
  animal.eat();
  Bird bird;
  bird.eat();
  bird.fly();
  Dog dog;
  dog.eat();
  // dog.fly(); // NOT ALLOWED!
  dog.bark();
}