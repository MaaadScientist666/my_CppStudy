#include "MyArray.hpp"
int main() {
    MyArray<int> array(3);
    array.my_push_back(3);
    array.my_push_back(4);
    array.my_push_back(5);
    for (int i=0;i<array.cur_size;i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    array.my_pop();
    for (int i=0;i<array.cur_size;i++) {
        cout<<array[i]<<" ";
    }


}