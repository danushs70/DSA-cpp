#include<iostream>
using namespace std;
class Animal {
public:
	int a = 9;
    void eat() {
        cout << "Eating"<<endl;
    }
};

class Dog : virtual public Animal {
public:
	int a = 10;
};

class Cat : virtual public Animal {
public:
	int a = 11;
};

class Puppy : public Dog, public Cat {};

int main()
{
	Puppy p;
	p.eat();
	//cout<<p.a<<endl;
	cout<<p.Cat::a<<endl;
	cout<<p.Dog::a<<endl;
}