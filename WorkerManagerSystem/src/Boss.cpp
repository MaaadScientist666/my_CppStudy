//
// Created by 29436 on 2026/8/7.
//

#include "../include/Boss.h"

Boss::Boss(int id, string name, int dep_id) {
    this->id = id;
    this->name =name;
    this->dep_id = dep_id;
}

void Boss::get_info() {
    cout<<"职工编号 "<<this->id<<endl;
    cout<<"职工姓名："<<this->name<<endl;
    cout<<"职工岗位： "<<this->get_dep_name()<<endl;
    cout<<"岗位职责：管理所有事物\n";
}

string Boss::get_dep_name() {
    return "老板";
}
