#include<iostream>
using namespace std;


class Animal {
public:
     virtual void speak() {
        cout << "animals are speaking" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "cats are speaking" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "dogs are speaking" << "\n";
    }
};

void dospeak(Animal &animal) {
    animal.speak();
}

int main() {
    Cat cat;
    dospeak(cat);
}

