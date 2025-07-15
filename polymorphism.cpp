#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
public:
  virtual void make_noise() {
    cout << "<Unknown Animal>" << endl;
  }
};

class Dog : public Animal {
public:
  void make_noise() override {
    cout << "Woof" << endl;
  }
};

class Bird : public Animal {
public:
  void make_noise() override {
    cout << "Chirp" << endl;
  }
};

void call_make_noise(Animal &input_animal) {
  input_animal.make_noise();
}

int main() {
  // What does this do?
  Dog dog1;
  Animal animal1;
  Animal animal_or_dog = Dog();

  dog1.make_noise(); //outputs "Woof"
  animal1.make_noise(); //Unknown animal
  animal_or_dog.make_noise(); //Unknown animal

  call_make_noise(dog1); //Unknown animal
  call_make_noise(animal1); //Unknown animal
  call_make_noise(animal_or_dog); //Unknown animal
}