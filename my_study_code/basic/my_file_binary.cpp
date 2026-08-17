#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;


class Person {
public:
    // Person(const char *n, int age) {
    //     strcpy(name,n);
    //     this->age = age;
    // }
    char name[64];
    int age;
};

void ts01() {
    Person p1("zhang san",18);
    ofstream ofs;
    ofs.open("person.txt",ios::out|ios::binary);
    if (!ofs.is_open()) {
        cout<<"failed to open file\n";
        return;
    }
    ofs.write((const char* )&(p1),sizeof(p1));
    ofs.close();
}

void ts02() {
    ifstream ifs;
    ifs.open("person.txt",ios::in);
    if (!ifs.is_open()) {
        cout<<"failed to open file\n";
        return;
    }
    Person p2;
    ifs.read((char *)&p2,sizeof(p2));
    cout<<"name = "<<p2.name<<"\n"<<"age = "<<p2.age<<"\n";
    ifs.close();
}

int main() {
    ts01();
    ts02();
}