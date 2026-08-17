#include<iostream>
using namespace std;


struct student {
    string name;
    int score;
};

struct teacher {
    string name;
    student stu[5];
};

void fill_data(teacher teacher[], int len) {
    string tname = "教师";
    string sname = "学生";
    string name_seed = "ABCDE";
    for(int i=0;i<len;i++){
        teacher[i].name = tname + name_seed[i];
        for (int j =0;j<5;j++) {
            teacher[i].stu[j].name = sname + name_seed[j];
            teacher[i].stu[j].score = rand() % 61 + 40;
        }
    }
}

void print_data(teacher teacher[], int len) {
    for (int i=0;i<len;i++) {
        cout<<teacher[i].name<<"的学生成绩如下："<<endl;
        for(int j=0;j<5;j++) {
            cout<<teacher[i].stu[j].name<<"  "<<teacher[i].stu[j].score<<endl;
        }
    }
}

int main() {
    teacher teacher[3];
    fill_data(teacher, 3);
    print_data(teacher,3);
}


