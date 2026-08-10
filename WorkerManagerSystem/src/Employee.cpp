//
// Created by 29436 on 2026/8/7.
//
#include "../include/Employee.h"

Employee::Employee(int id, string name, int dep_id) {
    this->id = id;
    this->name = name;
    this->dep_id = dep_id;
}

void Employee::get_info() {
    cout<<"职工编号 "<<this->id<<endl;
    cout<<"职工姓名："<<this->name<<endl;
    cout<<"职工岗位： "<<this->get_dep_name()<<endl;
    cout<<"岗位职责：完成经理给的任务\n";
}

string Employee::get_dep_name() {
    return "普通职员";
}
