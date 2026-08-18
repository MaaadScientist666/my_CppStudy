#include<list>
#include<iostream>
#include<algorithm>
using namespace std;


class Person {
public:
    Person(string name,int age,int height) {
        this->name = name;
        this->age = age;
        this->height = height;
    }
    string name;
    int age;
    int height;
};

bool my_sort(Person &a,Person &b) {
    if (a.age == b.age) {
        return a.height < b.height;
    }
    else return a.age < b.age;
}

int main() {
    list<Person> p;
    p.push_back(Person("liubei",35,175));
    p.push_back(Person("guanyu",45,180));
    p.push_back(Person("zhangfei",40,170));
    p.push_back(Person("zhaoyun",25,190));
    p.push_back(Person("sunquan",35,160));
    p.push_back(Person("liubei",35,200));
    p.sort(my_sort);
    for (list<Person>::iterator it = p.begin();it!=p.end();it++) {
        cout<<"name is "<<(*it).name<<" ";
        cout<<"age is "<<(*it).age<<" ";
        cout<<"height is "<<(*it).height<<endl;
    }
}