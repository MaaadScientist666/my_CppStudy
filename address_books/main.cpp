/**
*  通讯录管理系统
 *
 * 本系统是一个基于C++的控制台应用程序，用于管理个人通讯录信息。
 * 用户可以添加、显示、删除、查找、修改和清空联系人。
 *
 * @section 功能列表
 *
 * @subsection add 添加联系人
 *    向通讯录中添加新的联系人，需要输入以下信息：
 *    - 姓名（字符串）
 *    - 性别（字符串，如"男"/"女"）
 *    - 年龄（整数）
 *    - 联系电话（字符串）
 *    - 家庭住址（字符串）
 *    @note 通讯录最多可容纳1000人
 *
 * @subsection display 显示联系人
 *    遍历并显示通讯录中所有联系人的完整信息。
 *    如果通讯录为空，则提示用户。
 *
 * @subsection delete 删除联系人
 *    根据用户输入的姓名，在通讯录中查找并删除对应的联系人。
 *    如果找到，则删除该联系人并提示成功；
 *    如果未找到，则提示用户。
 *
 * @subsection search 查找联系人
 *    根据用户输入的姓名，在通讯录中查找并显示对应的联系人信息。
 *    如果找到，则显示该联系人的完整信息；
 *    如果未找到，则提示用户。
 *
 * @subsection modify 修改联系人
 *    根据用户输入的姓名，在通讯录中查找对应的联系人。
 *    如果找到，则允许用户重新输入该联系人的所有信息；
 *    如果未找到，则提示用户。
 *
 * @subsection clear 清空联系人
 *    删除通讯录中所有联系人的信息。
 *    操作前会进行二次确认，防止误操作。
 *
 * @subsection exit 退出通讯录
 *    退出当前通讯录管理系统，结束程序运行。
 */

#include<iostream>
#include<string>
using namespace std;
#define MAX  1000

struct contact_info { //联系人结构体
    string name;
    string sex;
    int age;
    string home;
    string number;
};

struct address_book { //通讯录结构体
    contact_info contact[MAX]; //容纳1000个联系人
    int size;
};

address_book A;

void add(address_book &a) {
    if (a.size<=999) {
        string tname;
        cout<<"请输入联系人姓名：";
        cin>>tname;
        string tsex;
        cout<<"请输入联系人性别：";
        cin>>tsex;
        int tage;
        cout<<"请输入联系人年龄：";
        cin>>tage;
        string tnumber;
        cout<<"请输入联系人电话号码：";
        cin>>tnumber;
        string thome;
        cout<<"请输入联系人住址：";
        cin>>thome;
        a.contact[a.size].name = tname;
        a.contact[a.size].sex = tsex;
        a.contact[a.size].age = tage;
        a.contact[a.size].home = thome;
        a.contact[a.size].number = tnumber;
        a.size++;
    }
    else {
        cout<<"通讯录人数已达上限！";
        return;
    }
}

void display(const address_book &a) {
    for (int i=0;i<a.size;i++) {
        cout<<"联系人姓名："<<a.contact[i].name<<"  ";
        cout<<"联系人年龄："<<a.contact[i].age<<"  ";
        cout<<"联系人性别："<<a.contact[i].sex<<"  ";
        cout<<"联系人电话："<<a.contact[i].number<<"  ";
        cout<<"联系人地址："<<a.contact[i].home<<"  ";
        cout<<endl;
    }
}

void delete_addressbook(address_book &a){
    string t_name;
    cout<<"请输入待删除的用户姓名：";
    cin>>t_name;
    for (int i=0;i<a.size;i++) {
        if (a.contact[i].name == t_name) {
            for (int j=i;j<a.size-1;j++) {
                a.contact[j].name = a.contact[j+1].name;
                a.contact[j].age = a.contact[j+1].age;
                a.contact[j].home = a.contact[j+1].home;
                a.contact[j].sex = a.contact[j+1].sex;
                a.contact[j].number = a.contact[j+1].number;
            }
            cout<<"删除成功!"<<endl;
            a.size--;
            return;
        }
    }
    cout<<"删除失败，联系人不存在"<<endl;
}

void search(address_book &a) {
    string t_name;
    cout<<"请输入联系人姓名：";
    cin>>t_name;
    for (int i=0;i<a.size;i++) {
        if (a.contact[i].name == t_name) {
            cout<<"联系人查找成功：";
            cout<<"联系人姓名："<<a.contact[i].name<<"  ";
            cout<<"联系人年龄："<<a.contact[i].age<<"  ";
            cout<<"联系人性别："<<a.contact[i].sex<<"  ";
            cout<<"联系人电话："<<a.contact[i].number<<"  ";
            cout<<"联系人地址："<<a.contact[i].home<<"  ";
            cout<<endl;
            return;
        }
    }
    cout<<"联系人不存在！";
}

void modify(address_book &a) {
    cout<<"请输入待修改联系人姓名：";
    string t_name;
    cin>>t_name;
    for (int i=0;i<a.size;i++) {
        if (a.contact[i].name == t_name) {
            cout << "请输入联系人新电话:" << endl;
            string t_number;
            cin>>t_number;
            a.contact[i].number = t_number;
            cout << "请输入联系人新年龄:" << endl;
            int t_age;
            cin>>t_age;
            a.contact[i].age = t_age;
            cout << "请输入联系人新住址:" << endl;
            string t_home;
            cin>>t_home;
            a.contact[i].home = t_home;
            cout<<"联系人信息修改成功!";
            return;
        }
    }
    cout<<"联系人不存在！";

}

void clear(address_book &a) {
    cout<<"您确认要清空通讯录吗？(Y/N)";
    char ans;
    cin>>ans;
    if (ans == 'n' || ans == 'N') {
        cout<<"已取消清空通讯录";
        return;
    }
    else if (ans == 'Y' || ans =='y') {
        a.size = 0;
        cout<<"清空通讯录成功！"<<endl;
        return;
    }
}

void show_menu() {
    while (1){
        cout<<"1.添加联系人"<<endl;
        cout<<"2.显示联系人"<<endl;
        cout<<"3.删除联系人"<<endl;
        cout<<"4.修改联系人"<<endl;
        cout<<"5.清空联系人"<<endl;
        cout<<"6.退出系统"<<endl;
        cout<<"请输入操作(1-6)"<<endl;
        int choice;
        cin>>choice;
        if (choice ==1 ) add(A);
        else if (choice ==2 ) display(A);
        else if (choice ==3 ) delete_addressbook(A);
        else if (choice == 4) modify(A);
        else if (choice == 5) clear(A);
        else if (choice == 6) {
            cout<<"已退出系统！";
            break;
        }
    }
}

int main() {

   show_menu();
}


