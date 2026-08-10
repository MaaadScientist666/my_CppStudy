//
// Created by 29436 on 2026/8/7.
//

#ifndef WORKERMANAGESYSTEM_EMPLOYEE_H
#define WORKERMANAGESYSTEM_EMPLOYEE_H
#include "Worker.h"

#endif //WORKERMANAGESYSTEM_EMPLOYEE_H

#pragma once
#include<iostream>
#include "Worker.h"
using namespace std;


class Employee : public Worker {
public:
   Employee(int id,string name,int dep_id);
   virtual void get_info() override;
   virtual string get_dep_name() override;
};