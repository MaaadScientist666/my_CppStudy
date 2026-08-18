#include <set>
#include<iostream>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    bool operator<(const Person &other) const {
        return this->age < other.age;
    }
    string name;
    int age;
};

int main() {
    //重载()方式
    {
        // class MyCmp {
        // public:
        //     bool operator()(int a,int b) const{
        //         return a > b;
        //     }
        // };
        // set<int , MyCmp> s2;
        // s2.insert(99);
        // s2.insert(199);
        // s2.insert(299);
        // s2.insert(399);
        // for (set<int>::iterator it = s2.begin();it!=s2.end();it++) {
        //     cout<<*it<<" ";
        // }
    }
    cout<<"\n--------------------------------------------\n";
    //重载<方式
    {
        // set<Person> s;
        // s.insert(Person("jj1",10));
        // s.insert(Person("jj2",11));
        // s.insert(Person("jj3",12));
        // for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
        // {
        //     cout << (*it).name << " ";
        // }
        // cout << endl;
    }
    cout<<"\n--------------------------------------------\n";
    //自定义数据类型重载()方式
    {
        class MyCmp {
        public:
            bool operator()(const Person &a,const Person &b) const {
                return a.age < b.age;
            }
        };
        set<Person,MyCmp> s;
        s.insert(Person("jj1",13));
        s.insert(Person("jj2",12));
        s.insert(Person("jj3",11));
        for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
        {
            cout << (*it).name << " ";
        }
        cout << endl;
    }
}