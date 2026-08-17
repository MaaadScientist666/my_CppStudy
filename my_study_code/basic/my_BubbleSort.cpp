#include<iostream>
using namespace std;

void BubbleSort(int *arr, int len) { //数组首地址，数组长度
    for (int i=0;i<len-1;i++) {
        for (int j=0;j<len-i-1;j++) {
            if (arr[j+1]<arr[j]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    for (int i=0;i<len;i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {

    int arr[] = {4, 3, 5, 7, 10, 99, 3, 2};
    BubbleSort(arr,8);
}