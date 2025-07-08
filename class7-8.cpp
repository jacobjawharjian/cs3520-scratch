#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>  
#include <ctime>    
#include <limits>   

using namespace std;

int main() {


    // auto - keyword that has the compiler figure out type

    // c++ will automatically do type conversion: 
    // int test = 500; 
    // long long_test = test;

    // //
    // unsigned int one = 1; 
    // int negative_one = -1; 

    // if (one < negative_one){ //if (one < (int) negative_one)
    //     cout << "One is greater than negative one!" << endl; 
    // }
    // else {
    //     cout << "One is less than negative one!" << endl; 
    // }

    //STRINGS
    string hello = "Hello, ";
    string world = "world!";
    string hello_world; 

    cout << hello + world << endl;
    hello += world;

    //ADVANCED STRING
    size_t pos = hello.find("ll"); 
    if (pos != hello.npos){
        cout << "Found \"ll\" at: " << pos << endl; 
    }
    else {
        cout << "Not found!!" << endl;
    }

}