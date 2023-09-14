 #include "head.h"
 #include "ListMethod.cpp" 
 #include "errormessage.cpp"
void InputElement(SqList &L); //
void print(ElemType &c); 
int main()
 {
    SqList La;
    ElemType e,preE,nextE; 
    int i; 

   //1. 初始化线性表La
    InitList_Sq(La);
   //2.将线性表重置为空
    SetEmpty(La);
   //3.判断是否为空
    if (IsEmpty(La)) {
        cout<<"list is empty"<<endl;
    }else{
        cout<<"list is not empty"<<endl;
    }
   //4.判断线性表的长度
    cout<<"长度: "<<ListLength(La)<<endl;
   
   //5.读入元素
    cout<<"Input A (请至少输入三个元素)"<<endl;;
    InputElement(La);
   
   //6.用e返回L中第i个元素的值 
    ListGetElem(La,i,e);
    cout<<"e: "<<e<<endl;
   //7.返回e的位置
   

   //8

   //9.�Һ�� 

   //10.����    

   //11.ɾ��Ԫ��e 

   //12.���� 
  // printf("La = { "); // �������A
  //  ListTraverse(La,print);
  //  printf("}\n");
  //  //2.�������Ա� 

  //  return 0;
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
	 ListInsert(L, i+1, e); 
   }
 }
void print(ElemType &c)
 {
   printf("%d ",c);
 }
