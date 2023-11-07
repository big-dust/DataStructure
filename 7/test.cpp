#include "fun.h"
int main()
{
 	BiTree T;
  BiTree C;
 	Tdatatype e;
    
    if(InitBiTree(T)){
        printf("初始化成\n");
    };
	
	//�ж��Ƿ�Ϊ��
 	if (BiTreeEmpty(T))
		printf("为空:yes\n");
	else
		printf("为空:no\n");

 	//������
	int len;
	len = BiTreeDepth(T);
	printf("长度:%d\n", len);
 	printf("*************开始初始化***************\n");

  Tdatatype definition[] = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, -1}; // ʾ��������
  int index = 0; // ���ڸ�������ĵ�ǰ����
  if (CreateBiTree(T, definition, index)) {
    printf("创建成功:\n") ;
    Traverse(T);
  } else {
    printf("创建失败.\n");
  }
 
  len = BiTreeDepth(T);
	printf("深度:%d\n", len);
 	// printf("������Ҫ���ҵ�Ԫ�أ�");
  scanf("%d",&e);
	if(Parent(T,e)){
    printf("父:%d\n",Parent(T,e)->data);
  }
  if(LeftChild(T,e)){
    printf("左孩子:%d\n",LeftChild(T,e)->data);
  }
  if(RightChild(T,e)){
    printf("右孩子:%d\n",RightChild(T,e)->data);
  }
  if(LeftSibling(T,e)){
    printf("左兄弟:%d\n",LeftSibling(T,e)->data);
  }
  if(RightSibling(T,e)){
    printf("右兄弟:%d\n",RightSibling(T,e)->data);
  }
  

  printf("*************当前新增用例树***************\n");
  Tdatatype definition2[] = {6, 7, 8, -1, -1, 9, -1, -1, 10, -1, -1};
  InitBiTree(C);
  int index2 = 0; 
  CreateBiTree(C,definition2,index2);
  Traverse(C);

    printf("在%d处插入用例",Parent(T,e)->data);
    InsertChild(Parent(T,e),0,C);
    Traverse(T);
    e=4;
    printf("删除%d的孩子结点",Parent(T,e)->data);
    DeleteChild(Parent(T,e),0);
    Traverse(T);

    DestroyBiTree(T);
    DestroyBiTree(C);
    return 0;
}
	
