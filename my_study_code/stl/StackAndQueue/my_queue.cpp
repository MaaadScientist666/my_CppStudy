#include<queue>
#include<iostream>
#include<string>
using namespace  std;


class Person {
public:
    Person(string name,int age) {
        this->name = name;
        this-> age =age;
    }
    string name;
    int age;
};

int main() {
    queue<Person> q;
    q.push(Person("唐僧",30));
    q.push(Person("猪八戒",1000));
    q.push(Person("孙悟空",2500));
    q.push(Person("沙悟净",2490));
    while (!q.empty()) {
        cout<<"队头元素-姓名："<<q.front().name<<" ";
        cout<<"队头元素-年龄 "<<q.front().age<<endl;
        q.pop();
    }
}