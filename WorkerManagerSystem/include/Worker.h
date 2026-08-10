//
// Created by 29436 on 2026/8/7.
//

#ifndef WORKERMANAGESYSTEM_WORKER_H
#define WORKERMANAGESYSTEM_WORKER_H

#endif //WORKERMANAGESYSTEM_WORKER_H

#pragma once
#include<iostream>
using namespace std;

class Worker {
public:
    int id;
    string name;
    int dep_id;
    virtual void get_info()=0;
    virtual string get_dep_name()=0;
};
