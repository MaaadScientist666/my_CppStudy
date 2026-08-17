#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// void my_print(int val) {
//     cout<<val<<" ";
// }

class Person {
public:
    int age;
    string name;
    Person(int age,string name) {
        this->age = age;
        this->name = name;
    }
};

int main() {
    // vector<int> v;
    // v.push_back(10);
    // v.push_back(11);
    // v.push_back(12);
    // v.push_back(13);
    // vector<int>::iterator vBegin;
    // vector<int>::iterator vEnd;
    // vBegin = v.begin();
    // vEnd = v.end();
    // while (vBegin != vEnd) {
    //     cout<<*vBegin<<" ";
    //     vBegin++;
    // } //遍历方式一

     // for (vector<int>::iterator it = v.begin();it!=v.end();it++) {
     //     cout<<*it<<" ";
     // } 遍历方式2
    //
    // for_each(v.begin(),v.end(),my_print)
    //STL提供的标准遍历算法
    //------------------------------------------------
    // vector<Person> v;
    // v.push_back(Person(19,"jiang"));
    // v.push_back(Person(5,"han"));
    // v.push_back(Person(6,"rui"));
    // v.push_back(Person(7,"yan"));
    // v.push_back(Person(8,"yang"));
    // for (vector<Person>::iterator it=v.begin();it!=v.end();it++) {
    //     cout<<"name = "<<(*it).name<<" age = "<<(*it).age;
    //     cout<<endl;
    // } //vector存放对象
    //-----------------------------------------------
    // vector<Person *> v;
    // Person * p[5];
    // Person p1(10,"jiang");
    // Person p2(11,"jiang");
    // Person p3(12,"jiang");
    // Person p4(13,"jiang");
    // Person p5(14,"jiang");
    // p[0] = &p1;
    // p[1] = &p2;
    // p[2] = &p3;
    // p[3] = &p4;
    // p[4] = &p5;
    // v.push_back(p[0]);
    // v.push_back(p[1]);
    // v.push_back(p[2]);
    // v.push_back(p[3]);
    // v.push_back(p[4]);
    // for (vector<Person*>::iterator it=v.begin();it!=v.end();it++) {
    //         cout<<"name = "<<(**it).name<<" age = "<<(**it).age;
    //         cout<<endl;
    //
    // } //vector存放对象指针
//-----------------------------------------------------------------------
    // vector<int> v1;
    // vector<int> v2;
    // vector<int> v3;
    // vector<int> v4;
    // for (int i=0;i<5;i++) {
    //     v1.push_back(i+1);
    //     v2.push_back(i+2);
    //     v3.push_back(i+3);
    //     v4.push_back(i+4);
    // }
    // vector<vector<int>> v;
    // v.push_back(v1);
    // v.push_back(v2);
    // v.push_back(v3);
    // v.push_back(v4);
    // for (vector<vector<int>>::iterator it=v.begin();it!=v.end();it++) {
    //     for (vector<int>::iterator it2=(*it).begin();it2!=(*it).end();it2++) {
    //         cout<<*it2<<" ";
    //     }
    //     cout<<endl;
    // }  vector嵌套容器
    //----------------------------------------------------------------
}