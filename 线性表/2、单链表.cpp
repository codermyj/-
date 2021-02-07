#include<stdio.h>
#include<iostream>
using namespace std;

typedef int ElemType;
// 0��������
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

//1����ʼ������
int InitList_L(LinkList &L) {
    L = new LNode;
    L->next = NULL;
    return 1;
}

// 2���жϵ�����Ϊ��
int IsEmpty_L(LinkList &L) {
    return L->next == NULL ? 1 : 0;
}

// 3�����ٵ�����
int DestroyList_L(LinkList &L) {
    LNode *p;
    while(L) {
        p = L;
        L = L->next;
        delete p;
    }
    return 1;
}

//4����յ�����
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

//5�����㵥������
int ListLength_L(LinkList &L) {
    LNode *p;
    p = L ->next;
    int i = 0;
    while(p){
        i++; //��ǰ�ڵ㲻Ϊnullptr���������1
        p = p ->next;
    }
    return i;
}

//6�����ҵ�����ĵ�i��Ԫ��
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

// 7����ֵ����
// 7.1 ���ص�ַ
LNode *LocateElem_L_ADDR(LinkList &L, ElemType e) {
    LNode *p;
    p = L -> next;
    while(p&&p->data!=e) {
        p = p ->next;
    }
    return p;
}
// 7.2����λ��
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

// 8���ڵ�i��λ�ò���Ԫ��e
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

// 9��ɾ����i�����
int ListDelete_L(LinkList &L, int i, ElemType e) {
    //���ҵ���i-1�����
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

// 10���½�����
//10.1 ͷ�巨
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
//10.2 β�巨
void CreateList_W(LinkList &L, int n) {
    L = new LNode;
    L ->next = nullptr;
    // rβָ��
    LNode *r = L;
    // p�½��
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
