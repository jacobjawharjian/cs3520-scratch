#include <iostream>
#include <vector>
using namespace std;

enum class MealSize {
    none, 
    small, 
    medium, 
    large
};

string mealSizeToString(MealSize size) {
    switch (size) {
        case MealSize::none: return "None";
        case MealSize::small: return "Small";
        case MealSize::medium: return "Medium";
        case MealSize::large: return "Large";
    }
    return "Unknown";
}

struct Meal {
    MealSize burger_size, fries_size, drink_size;
    
};

class Restaurant {
    int num_employees; 
    vector<Meal> todays_orders;

public: 

     void print() const { 
    cout << num_employees 
     << " working on " 
     << todays_orders.size()
     << " meals."
     << endl; 
    }

    Restaurant() {
        num_employees = 8; 
        todays_orders = {};
        cout << "Default Restaurant status: " << endl;
        print();
    }

    Restaurant(int _num_employees, vector<Meal> _todays_orders)
        : num_employees(_num_employees), todays_orders(_todays_orders) {
      cout << "Restaurant status: " << endl;
      print();
        }
    
    int count_large_drinks() const {
    int count = 0;
    for (const Meal& m : todays_orders) {
        if (m.drink_size == MealSize::large) {
            count++;
        }
    }
    return count;

    
}

void print_orders() const {
        for (size_t i = 0; i < todays_orders.size(); ++i) {
            const Meal& m = todays_orders[i];
            cout << "Meal " << i + 1 << ": "
                 << "Burger: " << mealSizeToString(m.burger_size) << ", "
                 << "Fries: " << mealSizeToString(m.fries_size) << ", "
                 << "Drink: " << mealSizeToString(m.drink_size) << endl;
        }
    }

};




int main() {
    // Create some Meal objects
    Meal meal1 = {MealSize::large, MealSize::medium, MealSize::small};
    Meal meal2 = {MealSize::medium, MealSize::medium, MealSize::large};
    Meal meal3 = {MealSize::small, MealSize::none, MealSize::large};

    vector<Meal> todays_meals = {meal1, meal2, meal3};

    Restaurant r1(10, todays_meals);

    Restaurant r2;

    cout << "Large drinks: " << r1.count_large_drinks() << endl;

    return 0;
}


