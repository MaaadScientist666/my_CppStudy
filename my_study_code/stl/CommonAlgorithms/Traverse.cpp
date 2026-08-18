#include<algorithm>
#include<iostream>
#include <vector>
using namespace std;

void printVector(vector<int>v) {
    for (int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void print(int a ) {
    cout<<a<<" ";
}

int nth(int val) {
    return val;
}

int main() {
    vector<int>v;
    for (int i=0;i<10;i++) {
        v.push_back(i+rand()%10);
    }
    printVector(v);
    vector<int>::iterator it = v.begin();
    for_each(it,v.end(),print); //for_each遍历
    vector<int> v2(20);
    transform(it,v.end(),v2.begin(),nth);
    cout<<endl;
    printVector(v2);
}