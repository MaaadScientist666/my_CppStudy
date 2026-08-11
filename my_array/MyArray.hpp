#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray {
public:
    MyArray(int capacity) {
        array_size = capacity;
        p_array= new T[array_size];
        cur_size = 0;
    } //默认构造函数
    MyArray& operator=(const MyArray &my_array) {
        if (this == &my_array) return *this;
        if (this->p_array!=nullptr) {
            delete[] this->p_array;
            this->cur_size = 0;
            this ->array_size = my_array.array_size;
        }
        p_array = new T[my_array.array_size];
        this->array_size = my_array.array_size;
        this->cur_size = my_array.cur_size;
        for (int i=0;i<my_array.cur_size;i++) {
            this->p_array[i] = my_array.p_array[i];
        }
        return *this;
    } //重载‘=’
    MyArray(const MyArray & my_array) {
        this->array_size = my_array.array_size;
        this->cur_size = my_array.cur_size;
        this->p_array = new T[my_array.array_size];
        for (int i=0;i<this->cur_size;i++) {
            this->p_array[i] = my_array.p_array[i];
        }
    } //拷贝构造函数
    T& operator[](int index) {
        return this->p_array[index];
    } //重载[]，实现数组访问
    ~MyArray() {
        if (this->p_array!=nullptr) {
            delete[] p_array;
            p_array=nullptr;
            this->array_size = 0;
            this->cur_size = 0;
        }

    } //析构函数
    void my_push_back(const T &val) {
        if (cur_size+1<=array_size) {
            cur_size++;
            p_array[cur_size-1] = val;
        }
        else {
            cout<<"数组空间不足！";
        }
    }
    void my_pop() {
        if (cur_size == 0) return;
        else {
            this->cur_size--;
        }
    }


    int array_size;//容量
    T * p_array;//指向数组的内存地址的指针
    int cur_size;//数组大小
};
