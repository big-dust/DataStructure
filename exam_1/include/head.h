 // head.h (程序名)

#ifndef CA5E0248_0A46_4FA7_9F3C_64114FD495E0
#define CA5E0248_0A46_4FA7_9F3C_64114FD495E0

#ifndef A79B6452_5012_40D1_8AA3_84F057535BE3
#define A79B6452_5012_40D1_8AA3_84F057535BE3
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
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2 //因为在math.h中已定义OVERFLOW的值为3,故去掉此行
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE
 typedef int ElemType;
 struct SqList {
	 ElemType* elem;
	 int length;
	 int listsize;
	 int incrementsize;
 };

extern Status InitList(SqList& l, int maxsize = LIST_INIT_SIZE, int incresize = LISTINCREMENT);
extern Status ClearList(SqList& l);
extern Boolean ListEmpty(SqList l);
extern int ListLength(SqList l);
void InputElement(SqList &L); //输入集合元素到线性表L中 
extern Status InsertElem(SqList& l, int i, ElemType e);
extern Status GetElem(SqList l, int i, ElemType& e);
extern int LocateElem(SqList l, ElemType e);
extern Status PriorElem(SqList l, ElemType cur_e, ElemType& pre_e);
extern Status NextElem(SqList l, ElemType cur_e, ElemType& next_e);
extern Status InsertElem(SqList& l, int i, ElemType e);
extern Status ListTraverse(SqList l);
extern Status ListDelete(SqList& l, int i, ElemType& e);
extern Status DestroyList(SqList& l);
void print(ElemType &c); 


#endif /* A79B6452_5012_40D1_8AA3_84F057535BE3 */



#endif /* CA5E0248_0A46_4FA7_9F3C_64114FD495E0 */
