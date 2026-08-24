#include <iostream>
using namespace std;
#define MAX_SIZE 100


struct SqStack {
    int *base;
    int *top;
    int stackSize; //最大容量
};

static bool initSqStack(SqStack &s) {
    s.base = new int[MAX_SIZE];
    if (s.base == nullptr) return false;
    s.top = s.base;
    s.stackSize = MAX_SIZE;
    return true;
} //初始化

static bool destroySqStack(SqStack &s) {
    if (s.base == nullptr) return false;
    delete[] s.base;
    s.top = nullptr;
    s.base = nullptr;
    return true;
} //销毁顺序栈

static bool is_SqStackEmpty(SqStack s) {
    if (s.base == s.top) return true;
    else return false;
} //判空

static int get_SqStackLength(SqStack s) {
    return s.top - s.base;
} //获取长度

static bool get_SqStackTop(SqStack s,int &e) {
    if (s.base == s.top) return false;
    e = *(s.top-1);
    return true;
} //取栈顶

static bool clearSqStack(SqStack &s) {
    if (s.base == nullptr) return false;
    s.top = s.base;
    return true;
} // 清空栈

static bool pushSqStack(SqStack &s,int e) {
    if (s.base == nullptr) return false;
    if (s.top - s.base == MAX_SIZE) return false;
    *(s.top) = e;
    s.top++;
    return true;
} //将e压栈

static bool popSqStack(SqStack &s,int &e) {
    if (s.top == s.base) return false;
    e = *(s.top-1);
    s.top--;
    return true;
}//出栈，用e返回

static void printSqStack(SqStack s) {
    if (s.top == s.base) {
        cout<<"栈为空！"<<endl;
        return;
    }
    cout<<"当前栈内元素个数为："<<get_SqStackLength(s)<<endl;
    while (s.top != s.base) {
        cout<<*(s.top-1)<<" ";
        s.top--;
    }
    cout<<endl;
} //打印所有栈内元素

struct StackNode {
    int data;
    StackNode* next;
}; //链式栈的节点数据结构 不需要头节点，设头指针指向首元节点，插入删除都在栈顶执行

void initLinkStack(StackNode* &s) {
    s = nullptr;
} //初始化链栈

bool is_LinkStackEmpty(StackNode* s) {
    if (s == nullptr) return true;
    return false;
}

bool pushLinkStack(StackNode* &s,int val) {
    StackNode* p = new StackNode;
    if (p == nullptr) return false;
    p->data = val;
    p->next = s;
    s = p;
    return true;
} //将val入栈

bool popLinkStack(StackNode* &s,int &val) {
    if (s == nullptr) return false;
    StackNode* p = s;
    val = s->data;
    s = s->next;
    delete p;
    return true;
} //出栈，用val返回

void printLinkStack(StackNode* s) {
    if (s == nullptr) {
        cout<<"链栈为空！"<<endl;
        return;
    }
    while (s!=nullptr) {
        cout<<s->data<<" ";
        s = s->next;
    }
    cout<<endl;
}

int main() {
    StackNode* s;
    initLinkStack(s);
    pushLinkStack(s,0);
    pushLinkStack(s,1);
    pushLinkStack(s,2);
    pushLinkStack(s,3);
    pushLinkStack(s,4);
    pushLinkStack(s,5);
    printLinkStack(s);
    int val;
    popLinkStack(s,val);
    popLinkStack(s,val);
    popLinkStack(s,val);
    printLinkStack(s);
    popLinkStack(s,val);
    popLinkStack(s,val);
    popLinkStack(s,val);
    printLinkStack(s);
}