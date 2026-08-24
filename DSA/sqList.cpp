#include<iostream>
using namespace std;
#define MAX_SIZE 100


class sqlist {
public:
        int *elem;
        int length;
};

static bool initList(sqlist &l) {
        l.elem = new int[MAX_SIZE];
        l.length = 0;
        return true;
} //初始化

static void destroyList(sqlist &l) {
        if (l.elem != nullptr) delete[] l.elem;
        l.elem = nullptr;
        l.length = 0;
} //销毁

static void clearList(sqlist &l) {
        l.length = 0;
} //清空

static int getLength(sqlist &l) {
        return l.length;
}

static bool isEmpty(const sqlist &l) {
        if (l.length == 0) return true;
        else return false;
}

static bool getElem(const sqlist &l, const int pos,int &e) {
        if (pos<0||pos>=l.length) return false;
        else {
                e = l.elem[pos];
                return true;
        }
} //取值到e中 o(1)

static int locateElem(sqlist &l ,int e) {
        for (int i=0;i<l.length;i++) {
                if (l.elem[i]==e) return i;
        }
        return -1;
} // 定位元素e,存在则返回序号(从0开始),不存在则返回-1

static bool insertList(sqlist &l,int e,int pos) {
        if (pos<0||pos>l.length) {
                return false;
        }
        if (l.length + 1 > MAX_SIZE) return false;
        for (int i = l.length;i>pos;i--) {
                l.elem[i] = l.elem[i-1];
        }
        l.elem[pos] = e;
        l.length++;
        return true;
} //在pos位置插入e

static bool deleteList(sqlist &l,int pos,int &e) {
        if (pos<0||pos>l.length-1) return false;
        e = l.elem[pos];
        for (int i = pos;i<l.length-1;i++) {
                l.elem[i] = l.elem[i+1];
        }
        l.length--;
        return true;
} //删除pos位置的元素并用e返回

void printList(const sqlist &l) {
        for (int i=0;i<l.length;i++) {
                cout<<l.elem[i]<<" ";
        }
        cout<<endl;
}

int main() {
        sqlist l;
        initList(l);
        insertList(l,1,0);
        insertList(l,2,0);
        insertList(l,3,0);
        insertList(l,4,0);
        insertList(l,5,0);
        printList(l);
        insertList(l,999,3);
        printList(l);
        int e=0;
        deleteList(l,3,e);
        printList(l);
        destroyList(l);
        printList(l);

}