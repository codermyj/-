#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//Ԥ���峣��
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_SIZE 100

typedef int Status;
typedef char ElemType;

// 0�����Ա���
typedef struct {
    ElemType *elem;
    int length;
} SqList;

// 1����ʼ�����Ա�
Status InitList_Sq(SqList &L) {
    L.elem = new ElemType[MAX_SIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

// 2���������Ա�
void DestroyList(SqList &L) {
    if(L.elem) delete L.elem;
}

// 3��������Ա�
void ClearList(SqList &L) {
    L.length = 0;
}

// 4�������Ա�L�ĳ���
int GetLength(SqList &L) {
    return L.length;
}

// 5���ж����Ա��Ƿ�Ϊ��
int IsEmpty(SqList &L) {
    if(L.length == 0)
        return 1;
    else
        return 0;
}

// 6��˳���ȡֵ
int GetElem(SqList &L, int i, ElemType &e) {
    if(i < 1 || i > L.length) return ERROR;
    e = L.elem[i-1];
    return OK;
}


int main(){
   cout << "main�������в���" <<endl;
}
