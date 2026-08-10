//
// Created by 29436 on 2026/8/7.
//

#ifndef WORKERMANAGESYSTEM_MANAGER_H
#define WORKERMANAGESYSTEM_MANAGER_H
#include "Worker.h"

#endif //WORKERMANAGESYSTEM_MANAGER_H

#pragma once
#include<iostream>
using namespace std;

class Manager : public Worker {
public:
    Manager(int id, string name, int dep_id);
    void get_info();
    string get_dep_name();
};
