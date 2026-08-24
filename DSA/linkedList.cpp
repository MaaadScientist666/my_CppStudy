#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};


static void printLinkList(Node * l) {
    Node* p = l->next;
    while (p!=nullptr) {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

static bool initNode(Node * &l) {
    l = new Node;
    l->next = nullptr;
    return true;
} //初始化

static bool is_empty(Node *l) {
    if (l == nullptr) return true;
    if (l->next == nullptr) return true;
    else return false;
} //判空

static bool destroyLinkList(Node *l) {
    while (l != nullptr) {
        Node *p = l;
        l = l->next;
        delete p;
    }
    return true;
} //销毁单链表

static bool clearLinkList(Node *l) {
    if (l == nullptr) return false;
    Node *p = l->next;
    while (p != nullptr) {
        Node *q = p->next;
        delete p;
        p = q;
    }
    l->next = nullptr;
    return true;
} // 清空单链表，保留头节点

static int getLength(Node *l) {
    if (l == nullptr) return 0;
    Node *p = l->next;
    int cnt = 0;
    while (p != nullptr) {
        cnt++;
        p = p->next;
    }
    return cnt;
} //求表长

static bool getElem(Node* l,int pos,int &e) {
    Node * p = l->next;
    int i=0;
    while (p!=nullptr && i<pos) {
        p=p->next;
        i++;
    }
    if (p==nullptr || i>pos) {
        return false;
    }
    e = p->data;
    return true;
} //获取第pos个元素，pos从0开始

static bool findElem(Node* l,int e,int &pos) {
    if (l==nullptr) return false;
    int cnt = 0;
    Node* p = l->next;
    while (p!=nullptr&&p->data!=e) {
        p=p->next;
        cnt++;
    }
    if (p==nullptr) return false;
    else {
        pos = cnt;
        return true;
    }
} //按值查找，若存在将位置信息返回到pos

static bool insertElem(Node* l,int e,int pos) {
    if (l == nullptr) return false;
    Node* p =l;
    int cnt = 0;
    while (p->next!=nullptr&&cnt<pos) {
        p=p->next;
        cnt++;
    }
    if (cnt!=pos) return false;
    Node* t = new Node;
    t->data = e;
    t->next = p->next;
    p->next = t;
    return true;
} // 在pos位置插入值为e的元素

static bool deleteElem(Node* l,int pos,int &e) {
    if (l==nullptr) return false;
    Node* p = l->next;
    Node* t = l;
    int cnt = 0;
    while (p!=nullptr&&cnt<pos) {
        p=p->next;
        t=t->next;
        cnt++;
    }
    if (cnt!=pos) return false;
    t->next = p->next;
    e = p->data;
    delete p;
    return true;
} //删除pos位置的元素并用e返回

static bool insertHead(Node* l,int val) {
    if (l==nullptr) return false;
    Node * p = new Node;
    p->data = val;
    p->next = l->next;
    l->next = p;
    return true;
} //头插法建立链表

static bool insertTail(Node* l ,int val) {
    if (l==nullptr) return false;
    Node* p = new Node;
    p->data = val;
    Node* tail = l;
    while (tail->next!=nullptr) {
        tail =tail->next;
    } //使tail指向尾节点
    tail->next = p;
    p->next = nullptr;
    return true;
} //尾插法

static void creatListHead(Node* &l,int n) {
    for (int i=0;i<n;i++) {
        Node* p =new Node;
        cin>>p->data;
        p->next = l->next;
        l->next = p;
    }
} //头插法建立n个数据量的链表
static void creatListTail(Node* l,int n) {
    Node* tail = l;
    // while (tail->next!= nullptr) {
    //     tail = tail->next;
    // }
    for (int i=0;i<n;i++) {
        Node* p = new Node;
        cin>>p->data;
        tail->next = p;
        p->next = nullptr;
        tail = p;
    }
} //尾插法建立n个数据量的链表

static Node* connectCirLinkList(Node* tail1,Node* tail2) {
    if (tail1==nullptr ||tail2==nullptr) return nullptr;
    Node* p =tail1->next;
    tail1->next = tail2->next->next;
    tail2->next = p;
    return tail2;
} // 合并带头节点加尾指针的循环链表

void unionList(Node* &l1,Node* l2) {
    int len1 = getLength(l1);
    int len2 = getLength(l2);
    for (int i=0;i<len2;i++) {
        int t;
        getElem(l2,i,t);
        int x;
        if (!findElem(l1,t,x)) {
            insertTail(l1,t);
        }
    }
} //合并两链表，到l1中，并去重

struct DulNode {
    int data;
    DulNode* next;
    DulNode* prior;
}; //双向链表节点



int main() {
    Node* l1;
    initNode(l1);
    creatListTail(l1,3);
    printLinkList(l1);
    Node* l2;
    initNode(l2);
    creatListTail(l2,3);
    printLinkList(l2);
    unionList(l1,l2);
    printLinkList(l1);
}
