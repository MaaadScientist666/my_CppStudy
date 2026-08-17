#include<iostream>
using namespace  std;

class Person {
public:
    int age;
    int* height;
    Person() : age(0), height(nullptr) {
        cout<<"默认构造函数的调用"<<"\n";
    }
    Person(int t_age, int t_height): age(t_age), height(new int(t_height)) {
        cout<<"带参数构造函数的调用"<<"\n";
    }
    Person(const Person & p): age(p.age), height(new int(*p.height)) {
        cout<<"拷贝类型构造函数的调用"<<"\n";
    }
    ~Person() {
        cout<<"析构函数的调用"<<"\n";
        if (height!=nullptr) {
            delete height;
            height = nullptr;
        }
    }
};


    //拷贝构造函数使用场景
    //1.使用一个已经创建完毕的对象来初始化一个新对象
// void ts01() {
//     Person p1(20);
//     Person p2(p1);
//     cout<<"age of p1 :"<<p1.age<<"\n";
//     cout<<"age of p2: "<<p2.age<<"\n";
// }
//
//
// //2.值传递的方式给函数参数传值
//
// void dowork(Person p) {
//
// }
// void ts02() {
//     Person p;
//     dowork(p);
// }
//
// //3.值方式返回局部对象
// Person dowork02() {
//     Person p1;
//     return Person(p1);
// }
// void ts03() {
//     Person p2 = dowork02();
// }


// void ts01(){
//     Person p1(18,180);
//     Person p2(p1);
//     cout<<"P1的年龄："<<p1.age<<"  p1的体重为："<<*p1.height<<"\n";
//     cout<<"P2的年龄："<<p2.age<<"  p2的体重为："<<*p2.height<<"\n";
//
//
// }

class A {
public:
    A() {
        cout<<"A类构造函数"<<"\n";
    }
    ~A() {
        cout<<"A类析构函数"<<"\n";
    }
};

class B {
public:
    A a;
    B() {
        cout<<"B类构造函数"<<"\n";
    }
    ~B() {
        cout<<"B类析构函数"<<"\n";
    }
};
int main() {
   B b;
}
