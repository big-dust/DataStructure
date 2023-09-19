#include "..\include\head.h"
using namespace std;

//初始化操作
Status InitList(SqList& l,int maxsize,int incresize) {
    l.elem = new ElemType[maxsize];
    l.length = 0;
    l.listsize = maxsize;
    l.incrementsize = incresize;
    return OK;
}

//销毁顺序表
Status DestroyList(SqList &l) {
    if (l.elem != nullptr) {
        delete[] l.elem;
    }
    l.length = 0;
    l.incrementsize = 0;
    l.listsize = 0;
    return OK;
}

//重置为空表
Status ClearList(SqList& l) {
    l.length = 0;
    return OK;
}

//检查是否为空
Boolean ListEmpty(SqList l) {
    if (l.length == 0) {
        return TRUE;
    }
    return FALSE;
}

//求长度
int ListLength(SqList l) {
    return l.length;
}

//找元素
Status GetElem(SqList l, int i, ElemType& e) {
    if (i<1 || i>l.length) {
        return ERROR;
    }
    e = l.elem[i-1];
    return OK;
}

//定位元素
int LocateElem(SqList l, ElemType e) {
    ElemType * p = l.elem;
    int i = 0;
    while(1){
        if (i+1 > l.length){
            break;
        }
        if ( p[i] == e ) {
            return i+1;
        }
        i++;
    }
    return 0;
}

//找前驱
Status PriorElem(SqList l, ElemType cur_e, ElemType& pre_e) { 
    if (l.length < 2){
        return ERROR;
    }
    ElemType * p_pre = l.elem;
    ElemType * p_cur = p_pre + 1;
    int i = 2;
    while(1){
        if (i > l.length){
            break;
        }
        if (*p_cur == cur_e){
            pre_e = *p_pre;
            return OK;
        }
        i++; p_cur++; p_pre++;
    }
    return ERROR;
}

//找后驱
Status NextElem(SqList l, ElemType cur_e, ElemType& next_e) {
    if (l.length < 2){
        return ERROR;
    }
    ElemType * p_cur = l.elem;
    ElemType * p_next = l.elem +1;
    int i = 1;
    while(1){
        if (i >= l.length){
            break;
        }
        if (*p_cur == cur_e){
            next_e = *p_next;
            return OK;
        }
        i++; p_cur++; p_next++;
    }
    return ERROR;
}

//扩充顺序表
void increment(SqList& l) {
    ElemType * tmp = new ElemType[l.listsize + l.incrementsize];
    
    for (int i = 0; i < l.length; i++)
    {
        tmp[i] = l.elem[i];
    }

    delete[] l.elem;
    l.listsize += l.incrementsize;
    l.elem = tmp;
}

//插入元素
Status InsertElem(SqList &l, int i, ElemType e){
    if (l.length >= l.listsize){
        return ERROR;
    }
    
    if (i < 1 || i > l.length+1){
        return ERROR;
    }
    
    if (i == l.length + 1){
        l.elem[i-1] = e;
        return OK;
    }

    for (int j = l.length - 1; j >= i - 1; j--)
    {
        l.elem[j+1]=l.elem[j];
    }

    l.elem[i-1]= e;
    l.length++;
    return OK; 
}


//删除元素
Status ListDelete(SqList& l, int i, ElemType& e) {
    if (i < 1 || i > l.length){
        return ERROR;
    }
    e = l.elem[i-1];

	for (int j = i + 1 ; j <= l.length; j++)
    {
        l.elem[j-2] = l.elem[j-1];
    }

    l.length--;
    return OK;
}

//依次输出所有元素
Status ListTraverse(SqList l) {
    for (int i = 0; i < l.length; i++)
    {
        cout<<i<<": "<<l.elem[i]<<endl;
    }
    return OK;
}

