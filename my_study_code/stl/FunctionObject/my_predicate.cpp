#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;

class GreaterFive {
public:
    bool operator()(int val){
        if (val > 5) return true;
        else return false;
    }
};

int main() {
    vector<int>v;
    for (int i=0;i<5;i++) {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());
    if (it == v.end()) cout<<"there is no element greater than 5\n";
    else cout<<"yes there is\n";
}