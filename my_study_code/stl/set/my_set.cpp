#include <set>
#include<iostream>
using namespace std;


void printSet(set<int> & s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//构造和赋值
void test01()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);

    //拷贝构造
    set<int>s2(s1);
    printSet(s2);

    //赋值
    set<int>s3;
    s3 = s2;
    printSet(s3);
}


//查找
void test02() {
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);
    cout<<*(s1.find(30))<<endl;
    cout<<s1.count(10)<<endl;
    pair<set<int>::iterator , bool> ret = s1.insert(10);
    if (ret.second == false) cout<<"error! element exists\n";
    else cout<<"insert successfully\n";
    pair<set<int>::iterator , bool> ret2 = s1.insert(999);
    if (ret2.second == false) cout<<"error! element exists\n";
    else {
        cout<<"insert "<<*ret2.first<< " successfully\n";
    }
}

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

    set<Person> s;
    s.insert(Person("jj1",10));
    s.insert(Person("jj2",11));
    s.insert(Person("jj3",12));
    for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << (*it).name << " ";
    }
    cout << endl;
    return 0;
}