#include<iostream>
using namespace std;


class MyAdd {
public:
    MyAdd() {
        count = 0;
    }
    int operator()(int a,int b) {
        count++;
        return a+b;
    }
    int count; //函数对象自己的状态
};

class MyPrint {
public:
    void operator()(const string &s){
        cout<<"string :"<<s<<endl;
    }
    void operator()(int a) {
        cout<<"int :"<<a<<endl;
    }

};

//函数对象作为参数
template<class t>
void do_sth(MyPrint a,t ts) {
    a(ts);
}

int main() {
    int a=10,b=15;
    MyAdd my_add;
    cout<<my_add.count<<endl;
    cout<<my_add(a,b)<<endl;
    cout<<my_add.count<<endl;
    MyPrint mp;
    do_sth(mp,"hello world");
    do_sth(mp,666);
}