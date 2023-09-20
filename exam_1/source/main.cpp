 #include "..\include\head.h"
using namespace std;

int main()
 {

   SqList La;
   ElemType e,preE,nextE; 
   int i; 

   //1.初始化线性表La 
   InitList(La);
   //3.将线性表重置为空  
   if (ClearList(La)) {
	   printf("已经重置链表\n");
   }

  // //4.判断La是否为空
  //  if (ClearList(La)) {
	//    printf("链表为空\n");
  //  }

  // //5.输出线性表的长度 
   printf("线性表长度为%d\n", ListLength(La));
  // 
  printf("\n************* Input A (请输入至少3个元素)***************\n");
  InputElement(La);

  // //6.用e返回L中第i个元素的值 
  i = 2;
  if (GetElem(La, i, e)) {
	  printf("L中第%d个元素的值%d\n", i,e);
  }
  cout<<"e:";
  cin>>e;
  // //7.返回e的位置 
  int location = LocateElem(La, e);
  printf("e的位置是%d\n", location);
  // //8.找前驱 
  e = 2;
  if (PriorElem(La, e, preE)) {
	  printf("pre_e是%d\n", preE);
  }

  // //9.找后继 
  if (NextElem(La, e, nextE)) {
	  printf("next_e是%d\n", nextE);
  }

  // //10.插入 
  if (InsertElem(La, i, e)) {
	  printf("插入后的线性表为\n");
	  ListTraverse(La);
	  printf("\n");
	}

  // //11.删除元素e 
  if (ListDelete(La, i, e)) {
	  printf("删除操作已经执行\n");
  }
  //12.遍历 
  printf("La = { "); // 输出集合A
  ListTraverse(La);
   printf("}\n");
  //2.销毁线性表 
   if (DestroyList(La)) {
	   printf("已经销毁线性表\n");
   }
   return 0;
}

void InputElement(SqList &L)
 {
   int i, num, e;
   
   printf("num  = ");
   scanf("%d", &num);
   printf("elem = ");
   for(i = 0; i < num; i++)
   {
	 scanf("%d", &e);
	 InsertElem(L, i+1, e); 
   }
 }
void print(ElemType &c)
 {
   printf("%d ",c);
 }
