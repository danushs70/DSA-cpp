#include <bits/stdc++.h>
using namespace std;

class Base {
public:

    // Virtual function
    virtual void display() {
        cout << "Base class function";
    }
};

class Derived : public Base {
public:

    // Overriding the base class function
    void display() override {  //override keyword not needed 
        cout << "Derived class function"<<endl;
    }
};

int main() {
    
    // Creating a pointer of type Base
    Base* basePtr;
    
    // Creating an object of Derived class
    Derived derivedObj;

    // Pointing base class pointer to 
    // derived class object
    basePtr = &derivedObj;
    // or 
    Base *basePtr2 = new Derived();
    // Calling the display function 
    // using base class pointer
    basePtr->display();
    basePtr2->display();
    return 0;
}