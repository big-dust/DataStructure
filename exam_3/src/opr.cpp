#include"..\include\head.h"

using namespace std;

//取集合A和集合B交集

LinkList overlap(LinkList a,LinkList b){
    Node * result = InitList();
    Node * p = a->next;
    while(p){
        if (LocateElem(b,p->data)!=0){
            ListInsert_back(p->data,result);
        }
        p = p->next;
    }
    return result;
}

//取并集
LinkList Union(LinkList a,LinkList b){
    Node * result = InitList();
    Node * p = a->next;
    while(p){
        ListInsert_back(p->data,result);
        p = p->next;
    }
    p = b->next;
    while(p){
        if (LocateElem(result,p->data)==0){
            ListInsert_back(p->data,result);
        }
        p = p->next;
    }
    return result;
}

//差集
LinkList SetDifference(LinkList a, LinkList b){\
    Node * result = InitList();
    Node * p = a->next;
    while(p){
        if (LocateElem(b,p->data)==0){
        ListInsert_back(p->data,result);
        }
        p = p->next;
    }
    return result;
}
