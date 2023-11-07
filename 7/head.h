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
#include <iostream>// cout,cin
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
typedef int Tdatatype;
typedef struct BiTNode 
{
  Tdatatype data;                
  struct BiTNode* lchild,*rchild;     
}BiTNode,*BiTree;

#endif /* B34B23C1_6E01_4F8E_B0C2_D1A7DD510A2A */

