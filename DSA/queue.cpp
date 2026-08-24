#define MAX_SIZE 100
#include<iostream>
using namespace std;

struct Queue {
    int * base;
    int front; //对头
    int rear; //队尾
}; //循环队列，解决假上溢

static bool initQueue(Queue &q) {
    q.base = new int[MAX_SIZE];
    q.front = 0;
    q.rear = 0;
    return true;
} //初始化

static bool destroyQueue(Queue &q) {
    if (q.base == nullptr) return false;
    delete[] q.base;
    q.base = nullptr;
    return true;
}

static bool clearQueue(Queue &q) {
    if (q.base == nullptr) return false;
    q.front = 0;
    q.rear = 0;
    return true;
}


static bool enQueue(Queue &q,int val) {
    if ((q.rear+1)%MAX_SIZE == q.front) return false;
    q.base[q.rear] = val;
    q.rear = (q.rear+1)%MAX_SIZE;
    return true;
} //入队

static bool deQueue(Queue &q, int &val) {
    if (q.rear == q.front) return false;
    val = q.base[q.front];
    q.front = (q.front+1)%MAX_SIZE;
    return true;
}//出队，将val返回

static int getQueueLength(const Queue &q) {
    return (q.rear - q.front+MAX_SIZE)%MAX_SIZE;
}

static void printQueue(const Queue &q) {
    if (q.front == q.rear) {
        cout<<"队列为空\n";
        return;
    }
    cout<<"队头为："<<q.base[q.front]<<endl;
    cout<<"队尾为："<<q.base[q.rear-1]<<endl;
    for (int i =q.front;i<q.rear;i++) {
        cout<<q.base[i]<<" ";
    }
    cout<<"\n";
}
//-----------------------------------------------------------------------------
struct QueueNode {
    int val;
    QueueNode* next;
}; //带头节点，front作为头指针指向头节点

struct LinkQueue {
    QueueNode* front;
    QueueNode* rear;
};

static bool initLinkQueueNode(LinkQueue &q) {
    q.front = new QueueNode;
    if (q.front == nullptr) return false;
    q.front -> next =nullptr;
    q.rear = q.front;
} //链式队列初始化

static bool enLinkQueue(LinkQueue &q,int val) {
    if (q.front == nullptr) return false;
    QueueNode* p = new QueueNode;
    p->val = val;
    p->next = nullptr;
    q.rear->next = p;
    q.rear = p;
    return true;
}

static bool deLinkQueue(LinkQueue &q,int &val) {
    if (q.front == q.rear) return false;
    val = q.front->next->val;
    QueueNode* p = q.front->next->next;
    delete q.front->next;
    q.front->next = p;
    if (q.rear == p)
        q.rear = q.front; //若删除最后一个节点，让rear指向头节点
    return true;
}

int main() {
   
}