#include <iostream>
#include <string>
#include <vector>
using namespace std;

void make_ordered(int& a, int& b) {
    if (b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
}
void make_ordered(double& a, double& b) {
    if (b < a) {
        double temp = a;
        a = b;
        b = temp;
    }
}

void vector_length_equals(const vector<int>& vec1, const vector<int>& vec2);

void vector_length_equals(const vector<int>& vec1, const vector<int>& vec2) {
    
    if (vec1.size() == vec2.size()) {
        cout << "YES!" << endl;
    } else {
        cout << "NO!" << endl;
    }
}



int main() {
    //EXERCISE 1
    vector<int> vec = {300, 300, 300};

    vec.resize(vec.size() + 7, 700);
    vec.insert(vec.begin() + 7, 800);


    for (int val : vec) {
        cout << val << " ";
    } cout << endl;

    vector<int> new_vec;

    while (!vec.empty()) {
        new_vec.push_back(vec.back());
        vec.pop_back();
    }
    
    for (int val : new_vec) {
        cout << val << " ";
    } cout << endl;


    //EXERCISE 2
    int x = 9, y = 3;
    double p = 4.5, q = 2.1;

    make_ordered(x, y);
    make_ordered(p, q);

    cout << "Ordered ints: " << x << ", " << y << endl;  
    cout << "Ordered doubles: " << p << ", " << q << endl;

    //EXERCISE 3
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};
    vector<int> c = {7, 8};

    vector_length_equals(a, b);  
    vector_length_equals(a, c);  

    return 0;

}