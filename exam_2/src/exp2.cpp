/**********************************************************/
 /*            线性表的静态存储结构测试程序            */
 /**********************************************************/
#include"../include/head.h"

int main()
{
	
	ElemType e, preE, nextE;
	int i,count;
	//用于前插
	Node* s1 = (Node*)malloc(sizeof(Node));
	s1->data = 7;
	s1->next = NULL;
	//用于后插
	Node* s2 = (Node*)malloc(sizeof(Node));
	s2->data = 8;
	s2->next = NULL;

	//初始化链表
	LinkList list = InitList();
	//重置链表  
	if (ClearList(list)) {
		printf("InitList: 重置完成\n");
	}

	//链表是否空
	if (ListEmpty(list)) {
		printf("ListEmpty: 链表为空\n");
	}
	else {
		printf("ListEmpty: 链表非空\n");
	}

	//链表长度
	printf("ListLength: %d\n", ListLength(list));
	
	printf("************* Input A (至少输入三个) ***************\n");
	InputElement(list);
	
	i = 2;
	if (GetElem(list,i, e)) {
		printf("GetElem: 第%d个元素是%d\n", i, e);
	}

	//定位元素
	e = 2;
	int location = LocateElem(list, e);
	printf("LocateElem: %d\n", location);
	//获得前驱元素 
	if (PriorElem(list, e, preE)) {
		printf("PriorElem: pre_elem: %d\n", preE);
	}
	//后继
	if (NextElem(list, e, nextE)) {
		printf("PriorElem: next_elem: %d\n", nextE);
	}
	//前插
	Node* p = list->next->next;
	if (ListInsert_front(list,p,s1)) {
		printf("ListInsert_front: 遍历前插后的的链表:\n");
		ListTraverse(list);
		printf("\n");
	}

	printf("%d",p->data);
	if (ListInsert_back(list, p, s2)) {
		printf("ListInsert_back: 遍历后插插后的的链表\n");
		ListTraverse(list);
		printf("\n");
	}
	 //删除链表
	if (ListDelete(list, p,e)) {
		printf("ListDelete: OK\n");
	}
	//遍历
	printf("list = {"); 
	ListTraverse(list);
	printf("}\n");
	//销毁链表 
	DestroyList(list);
	return 0;
}

