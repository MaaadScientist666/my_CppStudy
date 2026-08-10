#include "../include/WorkerManager.h"
#include "../include/Employee.h"
#include "../include/Worker.h"
#include "../include/Manager.h"
#include "../include/Boss.h"
#include<vector>

WorkerManager::WorkerManager() {
    init_worker();
    ifstream ifs;
    ifs.open("worker.txt",ios::in);
    if (!ifs.is_open()) {
        this->Worker_num = 0;
        this->wk_array.clear();
        this->file_is_empty = true;
        ifs.close();
        return;
    } //文件不存在
    char ch;
    ifs>>ch;
    if (ifs.eof()) {
        cout<<"文件为空\n";
        this->Worker_num = 0;
        this->wk_array.clear();
        this->file_is_empty = true;
        ifs.close();
        return;
    } //文件存在但是为空
    int num = this->get_num();
    cout<<"职工个数为："<<num<<endl;
    this->Worker_num = num;
}

WorkerManager::~WorkerManager() {
     if ( this->wk_array.size()!=0) {
         for (int i=0;i<this->wk_array.size();i++) {
             delete this->wk_array[i];
             this->wk_array[i] = nullptr;
         }
         this->wk_array.clear();
     }
} //析构函数

void WorkerManager::show_menu() {
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerManager::exit_system() {
    cout<<"欢迎下次使用\n";
    system("pause");
    exit(0);
}

void WorkerManager::add_wk() {
    int add_num;
    cout<<"请输入要添加员工数量：\n";
    cin>>add_num;
    for (int i=0;i<add_num;i++) {
        int id;
        string name;
        int d_select;
        cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
        cin >> id;
        cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
        cin >> name;
        cout << "请选择该职工的岗位：" << endl;
        cout << "1、普通职工" << endl;
        cout << "2、经理" << endl;
        cout << "3、老板" << endl;
        cin >> d_select;
        Worker *worker=nullptr;
        switch (d_select) {
            case 1:
                worker = new Employee(id,name,1);
                break;
            case 2:
                worker = new Manager(id,name,2);
                break;
            case 3:
                worker = new Boss(id,name ,3);
                break;
            default:
                break;
        }
        if (worker!=nullptr) {
            wk_array.push_back(worker);
            this->Worker_num++;
            cout<<"第"<<i+1<<"个成员添加成功！\n";
            this->save();
            this->file_is_empty = false;
        }
    }
    cout<<"当前总员工数量："<<this->Worker_num;
}

void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for (int i=0;i<wk_array.size();i++) {
        ofs<<this->wk_array[i]->id<<" "
        <<this->wk_array[i]->name<<" "
        <<this->wk_array[i]->dep_id<<endl;
    }
    ofs.close();

}

int WorkerManager::get_num() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int p_id;
    int num = 0;
    while (ifs>>id&&ifs>>name&&ifs>>p_id) {
        num++;
    }
    ifs.close();
    return num;
}

void WorkerManager::init_worker() {
    ifstream ifs;
    ifs.open("worker.txt",ios::in);
    int id;
    string name;
    int d_id;
    while (ifs>>id&&ifs>>name&&ifs>>d_id) {
        Worker * worker = nullptr;
        switch (d_id) {
            case 1:
                worker = new Employee(id,name,d_id);
                break;
            case 2:
                worker = new Manager(id,name,d_id);
                break;
            case 3:
                worker = new Boss(id,name,d_id);
                break;
            default:
                cout<<"职位信息有误！\n";
                continue;
        }
        this->wk_array.push_back(worker);
        this->Worker_num++;
    }
}

void WorkerManager::show_worker() {
    if (wk_array.size()==0) {
        cout<<"文件不存在或记录为空\n";
    }
    else {
        for(int i=0;i<this->wk_array.size();i++) {
            this->wk_array[i]->get_info();
        }
    }
}

int WorkerManager::is_exist(int id) {
    for (int i=0;i<this->wk_array.size();i++) {
        if (this->wk_array[i]->id == id) return i;
    }
    return -1;
} // 若存在返回其在数组中的位置，不存在返回-1

void WorkerManager::delete_worker() {
    cout<<"请输入待删除员工编号\n";
    int delete_id;
    cin>>delete_id;
    int index = is_exist(delete_id);
    if (index ==-1) cout<<"员工不存在！\n";
    else {
        delete this->wk_array[index];
        this->wk_array.erase(wk_array.begin()+index);
        this->Worker_num--;
        save();
    }
}

void WorkerManager::modify_woker() {
    int modify_number;
    cout<<"请输入待修改员工编号：";
    cin>>modify_number;
    int  index = is_exist(modify_number);
    if (index == -1) {
        cout<<"员工不存在！\n";
        return;
    }
    else {
        int id;
        string name;
        int dept_id;
        cout<<"请输入修改后的id";
        cin>>id;
        cout<<"请输入修改后的姓名:";
        cin>>name;
        cout<<"请选择修改后的岗位：\n";
        cout<<"1.普通职员\n";
        cout<<"2.经理\n";
        cout<<"3.老板\n";
        cin>>dept_id;
            Worker * worker = nullptr;
            switch (dept_id) {
                case 1:
                    worker = new Employee(id,name,dept_id);
                    break;
                case 2:
                    worker = new Manager(id,name,dept_id);
                    break;
                case 3:
                    worker = new Boss(id,name,dept_id);
                    break;
                default:
                    cout<<"职位信息有误！\n";
                    break;
            }
        if (worker != nullptr) {
            delete wk_array[index];
            this->wk_array[index] = worker;
            save();
            cout<<"修改成功！\n";
        }
        else cout<<"岗位输入有误，修改失败！\n";
    }
}

void WorkerManager::find_woker() {
    cout<<"请输入查找员工方式:\n";
    cout<<"1.按编号查找\n";
    cout<<"2.按姓名查找\n";
    int choice ;
    cin>>choice;
    if (choice == 1) {
        cout<<"请输入职工编号：";
        int find_num;
        cin>>find_num;
        int index;
        index = this->is_exist(find_num);
        if (index == -1) {
            cout<<"职工不存在！\n";
            return ;
        }
        else {
           this->wk_array[index]->get_info();
        }
    }
    else if (choice ==2) {
        cout<<"请输入待查找员工姓名：";
        string name;
        cin>>name;
        for (int i=0;i<this->wk_array.size();i++) {
            if (this->wk_array[i]->name == name) {
                this->wk_array[i]->get_info();
                return;
            }
        }
        cout<<"职员不存在！\n";
        return;
    }
}

 static bool sort_great(Worker * a,Worker * b) {
    return a->id > b->id;
}

static bool sort_less(Worker * a,Worker * b) {
    return a->id < b->id;
}

void WorkerManager::sort_worker() {
    cout<<"请输入需要的排序模式:(1-2)\n";
    cout<<"1.按职工号码降序排列\n";
    cout<<"2.按职工号码升序排列\n";
    int choice;
    cin>>choice;
    if (choice == 1) {
        sort(this->wk_array.begin(),this->wk_array.end(),sort_great);
        save();
        cout<<"员工排序成功！\n";
    }
    else if (choice == 2) {
        sort(this->wk_array.begin(),this->wk_array.end(),sort_less);
        save();
        cout<<"员工排序成功！\n";
    }
    else {
        cout<<"输入错误！\n";
    }
}

void WorkerManager::delete_all() {
    cout<<"您确定要清除所有员工吗？(y/n)\n";
    char choice;
    cin>>choice;
    if (choice == 'y'||choice == 'Y') {
        for (int i=0;i<wk_array.size();i++) {
            delete wk_array[i];
        }
        this->wk_array.clear();
        save();
        file_is_empty = true;
        Worker_num = 0;
        cout<<"清除所有员工成功！\n";
    }
    else return;
}
