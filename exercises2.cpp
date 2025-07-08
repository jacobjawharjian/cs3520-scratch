#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>  
#include <ctime>    
#include <limits>   

using namespace std;

void ex1(string str, int N)
{
    for(int i = 0; i < N; i++) {
        if (str[i] != 'l') {
            cout << str[i];
        }
    }
    cout << endl;
}

void ex2()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string input;
    cout << "Enter a number: ";
    getline(cin, input);

    stringstream ss(input);
    double number;

    if (ss >> number && ss.eof()) {
        cout << fixed << setprecision(5) << setw(10) << right << number << endl;
    } else {
        ofstream outFile("invalid_input.txt");
        if (outFile.is_open()) {
            outFile << input;
            outFile.close();
            cout << "Invalid input written to file." << endl;
        } else {
            cerr << "Error opening file." << endl;
        }
    }
}

void ex3()
{
    srand(time(0)); 
    int secret = rand() % 51; 

    int guess;
    while (true) {
        cout << "Guess the number (0-50): ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Please enter a valid number." << endl;
            continue;
        }

        if (guess == secret) {
            cout << "Congratulations!" << endl;
            break;
        } else if (guess < secret) {
            cout << "Too low!" << endl;
        } else {
            cout << "Too high!" << endl;
        }
    }
}

int main()
{
    string str = "Hello World"; 
    int N = str.length();

    ex1(str, N);
    // ex2()
    // ex3()
}
