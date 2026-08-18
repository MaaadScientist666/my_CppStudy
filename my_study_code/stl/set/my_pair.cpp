#include <set>
#include<iostream>
using namespace std;


int main() {
    pair<int,int> p1(10,12);
    pair<int,int> p2 = make_pair(10,12);
    cout<<"p1: "<<p1.first<<" "<<p1.second<<endl;
    cout<<"p2: "<<p2.first<<" "<<p2.second;
}