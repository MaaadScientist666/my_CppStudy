//
// Created by 29436 on 2026/8/7.
//

#ifndef WORKERMANAGESYSTEM_WORKERMANAGER_H
#define WORKERMANAGESYSTEM_WORKERMANAGER_H

#endif //WORKERMANAGESYSTEM_WORKERMANAGER_H
#pragma once

#define FILENAME "worker.txt"
#include<fstream>
#include "Worker.h"
#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>


class WorkerManager {
public:
    int Worker_num;
    bool file_is_empty;
    vector<Worker*> wk_array;
    WorkerManager();
    ~WorkerManager();
    void show_menu();
    void exit_system();
    void add_wk();
    void save();
    int get_num();
    void init_worker();
    void show_worker();
    void delete_worker();
    int is_exist(int id);
    void modify_woker();
    void find_woker();
    void sort_worker();
    void delete_all();
};