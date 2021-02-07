#include<stdio.h>
#include<iostream>
using namespace std;

typedef int ElemType;
// 0、链表定义
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

//1、初始化链表
int InitList_L(LinkList &L) {
    L = new LNode;
    L->next = NULL;
    return 1;
}

// 2、判断单链表为空
int IsEmpty_L(LinkList &L) {
    return L->next == NULL ? 1 : 0;
}

// 3、销毁单链表
int DestroyList_L(LinkList &L) {
    LNode *p;
    while(L) {
        p = L;
        L = L->next;
        delete p;
    }
    return 1;
}

//4、清空单链表
int ClearList_L(LinkList &L) {
    LNode *p, *q;
    q = L->next;
    while(q) {
        p = q;
        q = q ->next;
        delete p;
    }
    L -> next = NULL;
    return 1;
}

//5、计算单链表长度
int ListLength_L(LinkList &L) {
    LNode *p;
    p = L ->next;
    int i = 0;
    while(p){
        i++; //当前节点不为nullptr，则计数加1
        p = p ->next;
    }
    return i;
}

//6、查找单链表的第i个元素
int GetElem_L(LinkList &L, int i, ElemType &e) {
    LNode *p;
    int j;
    p = L -> next; j = 1;
    while(p && j != i) {
        p = p -> next;
        j++;
    }
    if(!p || j > i) return 0;
    e = p ->data;
    return 1;
}

// 7、按值查找
// 7.1 返回地址
LNode *LocateElem_L_ADDR(LinkList &L, ElemType e) {
    LNode *p;
    p = L -> next;
    while(p&&p->data!=e) {
        p = p ->next;
    }
    return p;
}
// 7.2返回位置
int LocateElem_L_NUM(LinkList &L, ElemType e) {
    LNode *p;
    int j;
    p = L ->next; j = 1;
    while(p&&p->data!=e){
        p = p->next;
        j++;
    }
    if(p)
        return j;
    else
        return 0;
}

// 8、在第i个位置插入元素e
int ListInsert_L(LinkList &L, int i, ElemType e) {
    LNode *p = L;
    int j = 0;
    while(p && j != i - 1) {
        p = p ->next;
        ++j;
    }
    if(!p || j > i - 1) return 0;
    LinkList S = new LNode;
    S ->data = e;
    S ->next = p ->next;
    p ->next = S;
    return 1;
}

// 9、删除第i个结点
int ListDelete_L(LinkList &L, int i, ElemType e) {
    //先找到第i-1个结点
    LNode *p = L;
    int j = 0;
    while((p -> next) && j != i-1){
        p = p ->next;
        ++j;
    }
    if(!(p ->next) || j < i-1) return 0;
    LNode *q = p ->next;
    p ->next = q ->next;
    e = q ->data;
    delete q;
    return 1;
}

// 10、新建链表
//10.1 头插法
void CreateList_H(LinkList &L, int n) {
    L = new LNode;
    L ->next = nullptr;
    LNode *p;
    int i;
    for(i = n; i !=0; --i) {
        p = new LNode;
        cin >> p ->data;
        p ->next = L ->next;
        L ->next = p;
    }
}
//10.2 尾插法
void CreateList_W(LinkList &L, int n) {
    L = new LNode;
    L ->next = nullptr;
    // r尾指针
    LNode *r = L;
    // p新结点
    LNode *p;
    int i;
    for(i = 0; i != n; ++i) {
        p = new LNode;
        p ->next = nullptr;
        cin >> p ->data;
        r -> next = p;
        r = p;
    }
}


int main(){
    return 0;
}
