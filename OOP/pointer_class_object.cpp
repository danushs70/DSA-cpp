#include <iostream>
using namespace std;

class Shape {
public:
	int a = 10;
	//virtual void draw() {
    void draw() {
        cout << "Shape Draw\n";
    }
};

class Circle : public Shape {
public:
	int a = 11;
    void draw(string str) {
        cout << "Circle Draw\n";
    }
};

int main() {
    Shape* s = new Circle();
    s->draw();
	cout<<"a from Shape: "<<s->a;
	
}