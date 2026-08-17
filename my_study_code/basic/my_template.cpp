#include<iostream>
#include<typeinfo>
using namespace  std;

template<typename T>
void my_swap(T &a,T &b) {
    T t;
    t = a;
    a = b;
    b = t;
} //泛型的比较函数

template<typename T>
void my_sort(T a[],int len) {
    for (int i=0;i<len-1;i++) {
        for (int j=0;j<len-i-1;j++) {
            if (a[j]>a[j+1]) {
                my_swap(a[j],a[j+1]);
            }
        }
    }
}  //泛型的排序函数

template<class T>
class Base
{
public:
    Base(T val) {
    }
    T m;
};

template<class T1, class T2>
class Son2 :public Base<T2>
{
public:
    Son2(T1 age,T2 name):Base<T2>( age)
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
    T1 age;
    T2 name;
};

void test02()
{
    Son2 child1(3,'a');
}

int main() {
   test02();
}



