// head.h (程序名)

#ifndef B34B23C1_6E01_4F8E_B0C2_D1A7DD510A2A
#define B34B23C1_6E01_4F8E_B0C2_D1A7DD510A2A
#include <string.h>
#include <ctype.h>
#include <malloc.h> // malloc()等
#include <limits.h> // INT_MAX等
#include <stdio.h> // EOF(=^Z或F6),NULL
#include <stdlib.h> // atoi()
#include <io.h> // eof()
#include <math.h> // floor(),ceil(),abs()
#include <process.h> // exit()
#include <iostream> // cout,cin
// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
typedef int ElemType;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct LNode {
	ElemType data;
	struct LNode* next;
} Node, * LinkList;

LinkList InitList();
Status DestroyList(LinkList& l);
Status ClearList(LinkList& l);
bool ListEmpty(LinkList l);
bool ListEmpty(LinkList l);
int ListLength(LinkList l); 
bool GetElem(LinkList l, int j, ElemType& e);
int LocateElem(LinkList l, ElemType e);
Status PriorElem(LinkList l, int cur_e, ElemType& pre_e);
Status NextElem(LinkList l, int cur_e, ElemType& next_e);
Status ListInsert_front(LinkList& l, Node* p, Node* s);
Status ListInsert_back(LinkList& l, Node* p, Node* s);
Status ListDelete(LinkList& l, Node* p, ElemType& e);
Status ListTraverse(LinkList& l);
void ErrorMessage(char* s);
void InputElement(LinkList& l);
void print(ElemType& c);

#endif /* B34B23C1_6E01_4F8E_B0C2_D1A7DD510A2A */
