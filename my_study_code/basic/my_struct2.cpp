#include<iostream>
using namespace std;


struct hero {
    string name;
    int age;
    string sex;
};

int main() {
    hero heros[5] = {
        {"Áõ±¸", 23, "ÄĞ"},
{"¹ØÓğ",22,"ÄĞ"},
{"ÕÅ·É",20,"ÄĞ"},
{"ÕÔÔÆ",21,"ÄĞ"},
{"õõ²õ",19,"Å®"},
    };
    for (int i=0;i<5;i++) {
        for (int j=0;j<5-i-1;j++) {
            if (heros[j+1].age<heros[j].age) {
                const hero t = heros[j+1];
                heros[j+1] = heros[j];
                heros[j] = t;
            }
        }
    }
    for (int i=0;i<5;i++) {
        cout<<heros[i].name<<"  "<<heros[i].age<<"  "<<heros[i].sex<<endl;
    }

}