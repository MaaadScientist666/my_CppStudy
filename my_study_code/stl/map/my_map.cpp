#include<iostream>
#include<map>
#include<string>
using namespace std;


class MyCmp {
public:
    bool operator()(int a,int b) const {
        return a>b;
    }
};

void printMap(map<int,int,MyCmp> &mp) {
    for (map<int,int,MyCmp>::iterator it=mp.begin();it!=mp.end();it++) {
        cout<<"key = "<<it->first<<"   ";
        cout<<"value = "<<it->second<<endl;
    }
}

int main() {
    map<int,int,MyCmp> mp;
    mp.insert(pair<int,int> (0,0));
    mp.insert(pair<int,int> (1,1));
    mp.insert(pair<int,int> (2,2));
    mp.insert(pair<int,int> (3,3));
    mp.insert(pair<int,int> (4,4));
    mp.insert(pair<int,int> (4,8)); //此语句插入key相同的元素，被编译器忽略
    mp[5]=5;
    mp[100]=100;
    printMap(mp);
}