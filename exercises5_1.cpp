#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    virtual ~Base() = default;

    string redefinable() const { 
        return "Base"; 
    }

    virtual string overridable() const { 
        return "Base"; 
    }
};

class Derived : public Base {
public:
    string redefinable() const { 
        return "Derived"; 
    }

    string overridable() const override { 
        return "Derived"; 
    }
};

void use_base(const Base& b) {
    cout << b.redefinable() << ' ' << b.overridable() << '\n';
}

void use_derived(const Derived& d) {
    cout << d.redefinable() << ' ' << d.overridable() << '\n';
}

int main() {
    Base    b;
    Derived d;

    use_base(b);    // Base Base
    use_base(d);    // Base Derived
    use_derived(d); // Derived Derived
}
