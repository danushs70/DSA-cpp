#include <bits/stdc++.h>
using namespace std;

class polymorphism_CT {
public:
    
    // Function to add two integers
    void add(int a, int b) {
        cout << "Integer Sum = " << a + b
        << endl;
    }
    
    // Function to add two floating point values
    void add(double a, double b) {
        cout << "Float Sum = " << a + b
        << endl ;
    }
};

int main() {
    polymorphism_CT CT;
    
    // add() called with int values
    CT.add(10, 2);

    // add() called with double value
    CT.add(5.3, 6.2);

    return 0;
}