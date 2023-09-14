#include<head.h>
#include"errormessage.cpp"
const int LIST_INIT_SIZE = 100;
const int LISRINCREMENT = 10;

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
    int increment;
} SqList;

void InitList_Sq(SqList &L, int maxsize = LIST_INIT_SIZE ,int incresize = LISRINCREMENT){
    L.elem = new ElemType[maxsize];
    L.length = 0;
    L.listsize = maxsize;
    L.increment = incresize;
}

bool SetEmpty(SqList &L){
    L.length=0;
    L.listsize=0;
    L.increment=0;
    delete L.elem;
    return true;
}

bool IsEmpty(SqList &L){
    if (L.length==0){
        return true;
    }
    return false;
}

int ListLength(SqList &L){
    return L.length;
}

bool ListInsert(SqList &L,int i , ElemType e){
    if (i>L.length||i<0){
        return false;
    }
    if (L.length==L.listsize){
        return false;
    }
    for(int j = L.length;j>i;j--){
        L.elem[j]=L.elem[j-1];
    }
    L.elem[i-1]=e;
    return true;
}

bool ListGetElem(SqList &L, int i, ElemType &e){
    if (i<0||i>L.length){
        return false;
    }
    e = L.elem[i-1];
    return true;
}

int LocateElem_Sq(SqList &L,ElemType e){
    
}