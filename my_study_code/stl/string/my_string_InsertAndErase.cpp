#include<string>
#include<iostream>
using namespace std;

void ts01() {
    string s1 = "DOTA2 IS BEST GAME EVER!";
    string s2 = "tarkov is best Game ever!";
    cout<<"s1 = "<<s1<<endl;
    cout<<"s2 = "<<s2<<endl;
    s1.insert(6,"and lol ");
    cout<<s1<<endl;
    s2.erase(0,7);
    cout<<s2<<endl;
}

int main() {
    ts01();
}