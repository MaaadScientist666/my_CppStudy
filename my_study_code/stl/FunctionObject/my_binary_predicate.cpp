#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;

bool cmp(int a,int b) {
    return a>b;
}

class cmp2 {
public:
    bool operator()(int a,int b) const {
        return a<b;
    }
};

int main() {
    vector<int>v;
    for (int i=0;i<10;i++) {
        v.push_back(i+rand());
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<"\n----------------------------\n";
    sort(v.begin(),v.end(),cmp2());
    for (int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
}