#include<string>
#include<iostream>
using namespace std;

void ts01() {
    string s1 = "hello";
    string s2 = "iello";
    int ret = s1.compare(s2);
    if (ret == 0) cout<<"s1 == s2\n";
    else if (ret > 0) cout<<"s1 > s2\n";
    else if (ret < 0) cout<<"s1 < s2\n";
}

int main() {
    ts01();
}