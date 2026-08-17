#include<iostream>
using namespace std;


class Calculator {
public:
    Calculator(int a, int b) {
        num1 = a;
        num2 = b;
    }

    virtual int get_result() =0;

    int num1, num2;
};

class Add : public Calculator {
public:
    Add(int a, int b) : Calculator(a, b) {
    };

    int get_result() override {
        return num1 + num2;
    }
};

class Mul : public Calculator {
public:
    int get_result() override {
        return num1 * num2;
    }
};

class Sub : public Calculator {
public:
    int get_result() override {
        return num1 - num2;
    }
};

int main() {
    Calculator *abc;
    abc = new Add(10,15);
    cout << abc->num1 << "+" << abc->num2 << "=" << abc->get_result();
    delete abc;
}
