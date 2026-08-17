#include<iostream>
#include<fstream>
using namespace std;


int main() {

    // ofstream ofs; // 1.创建对象
    // ofs.open("test.txt",ios::out|ios::app); // 2.打开文件
    // ofs<<"data of writen1234"<<endl; //写入文件
    // ofs.close(); //关闭文件

    ifstream ifs; //1.创建对象
    ifs.open("test.txt",ios::in); //2.打开文件
    if (!ifs.is_open()) {
        cout<<"failed to open file";
        return 0;
    }
    //第一种读法
    // char buf[1024]={0}; //3.读文件
    // while (ifs.getline(buf,sizeof(buf))){
    //     cout<<buf<<endl;
    // }
    //第二种读法
    // char buf[1024] = {0};
    // while (ifs>>buf) {
    //     cout<<buf<<endl;
    // }
    //第三种
    // string buf;
    // while (getline(ifs,buf)) {
    //     cout<<buf<<endl;
    // }
    //第四种
    char c;
    while ((c=ifs.get())!=EOF) {
        cout<<c<<" ";
    }
    ifs.close(); //4.关闭文件

}