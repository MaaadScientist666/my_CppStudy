#include<algorithm>
#include<list>
#include<iostream>
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

bool my_compare(int a,int b) {
    return a > b;
}

int main() {
    list<int> L;
    L.push_back(90);
    L.push_back(30);
    L.push_back(20);
    L.push_back(70);
    printList(L);
    L.sort();
    printList(L);
    L.sort(my_compare);
    printList(L);
    L.reverse();
    printList(L);
}