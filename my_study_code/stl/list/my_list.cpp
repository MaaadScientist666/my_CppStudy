#include<list>
#include<iostream>
#include <vector>
using namespace std;

void printList(const list<int> &l) {
    if (l.size()==0) cout<<"list is empty!\n";
    else {
        for (list<int>::const_iterator it=l.begin();it!=l.end();it++) {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

void ts01() {
    list<int> l;
    //尾插
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    //头插
    l.push_front(9);
    l.push_front(8);
    l.push_front(7);
    l.push_front(6);
    l.push_front(5);
    printList(l);
    //迭代器插入
    list<int>::iterator it = l.begin();
    l.insert(it,1000);
    printList(l);
    //删除
    it = l.begin();
    l.erase(++it);
    printList(l);
    l.remove(1000);
    printList(l);
    //清空
    l.clear();
    printList(l);
}

int main() {
    ts01();
}