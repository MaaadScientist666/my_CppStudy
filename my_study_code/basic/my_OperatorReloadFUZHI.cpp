#include<iostream>
using namespace std;

class Person {
public:
    int * age;
    Person() {
        age = nullptr;
    }
    Person(int const age) {
        this->age = new int(age);
    }
    Person(const Person &p) {
        this->age = new int(*p.age);
    }
    ~Person() {
        cout<<"析构函数的调用";
        if (age != nullptr) {
            delete age;
            age = nullptr;
        }
    }
    Person& operator=(Person &p) {
       if (this == &p) return *this;
       if (this->age != nullptr) {
           delete age;
           age = nullptr;
       }
        age = new int (*p.age);
        return *this;
    }
};

int main() {
    Person p1(10);
    Person p2(15);
    Person p3(20);
    p1 = p2 = p3;
   cout<<*p1.age<<*p2.age<<*p3.age;
    p1 = p1;
}