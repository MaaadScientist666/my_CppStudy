//
// Created by 29436 on 2026/8/7.
//

#ifndef WORKERMANAGESYSTEM_BOSS_H
#define WORKERMANAGESYSTEM_BOSS_H
#include "Worker.h"

#endif //WORKERMANAGESYSTEM_BOSS_H

#pragma once
#include<iostream>
using namespace std;


class Boss : public Worker {
public:
    Boss(int id,string name,int dep_id);
    void get_info();
    string get_dep_name();
};