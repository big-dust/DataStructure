/**********************************************************/
 /*           �������ľ�̬�洢�ṹ���Գ���                 */
 /**********************************************************/
#include "..\include\head.h"
void InputElement(LinkList& L); //���뼯��Ԫ�ص����Ա�L�� 
void print(ElemType& c);// �������Ա��ľ�̬�洢�ṹ
void ListInsert_back(LinkList L, int value_in);
Status InitList(LinkList& L);
Status DestroyList(LinkList& L);
Status ClearList(LinkList& L);
Status ListEmpty(LinkList L);
Status ListLength(LinkList L);
Status GetElem(LinkList L, ElemType i, ElemType& e);
int LocateElem(LinkList L, ElemType e);
Status ListInsert(LinkList& L,ElemType inser_e, ElemType e);
Status ListInsert_back(LinkList L, LNode* p, LNode* s);
Status ListDelete(LinkList& L,ElemType& e);
Status PriorElem(LinkList L, ElemType cur_e, ElemType& pre_e);
Status NextElem(LinkList L, ElemType cur_e, ElemType& next_e);
Status ListTraverse(LinkList &L);
LinkList Intersection(LinkList LA, LinkList LB);
LinkList Union(LinkList LA, LinkList LB);
LinkList Minus(LinkList LA, LinkList LB);

int main()
{
	LinkList  La, Lb, Lc,Ld,Le;
	ElemType e,pre_e, next_e,inser_e;
	LNode * s;
	int i, count;
	
	//1.��ʼ�����Ա�La 
	 
	InitList(La);
	InitList(Lb);
	InitList(Lc);
	InitList(Ld);
	InitList(Le);
	
	 printf("�Ѵ�����\n");
	//3.�����Ա�����Ϊ��
	// ClearList(La);
		if (ClearList(La)&&ClearList(Lb)&&ClearList(Lc)&&ClearList(Le))
		{
			printf("�Ѿ����ã�\n");
		}
	//4.�ж�La�Ƿ�Ϊ��
	if (ListEmpty(La) == TRUE)
		printf("yes\n");
	else
		printf("no\n");

	//5.������Ա��ĳ���
	int La_len;
	La_len = ListLength(La);
	printf("the length is %d\n", La_len);

	
	printf("************* Input A (����������3��Ԫ��)***************\n");
	InputElement(La);
	InputElement(Lb);
	//����

	//����
	printf("AnB=");
	
	Lc = Intersection(La, Lb);
	ListTraverse(Lc);
	//����
	printf("\nAUB=");
	Ld=Union(La, Lb);
	ListTraverse(Ld);
	//�
	printf("\nA-B=");
	Le = Minus(La, Lb);
	ListTraverse(Le);
	printf("\n");
	//6.��e����L�е�i��Ԫ�ص�ֵ
	//Getelem

	/*/printf("��������ҵ�Ԫ�ش���");
	scanf_s("%d", &i);
	if (GetElem(La, i, e))
	{

		printf("L�е�%d��Ԫ�ص�ֵ%d\n", i, e);
	}

	//7.����e��λ��
	 //LocateElem(La,e);
	printf("������Ҫ���ҵ�Ԫ�أ�\n");
	scanf_s("%d", &e);
	int location = LocateElem(La, e);
	printf("%dԪ�ص�λ����%d\n", e,location);
	
	//8.��ǰ��
	// PriorElem(La,cur_e,&pre_e);
	printf("������Ҫ����ǰ����Ԫ�أ�\n");
	scanf_s("%d", &e);
	if (PriorElem(La, e, pre_e))
	{
		printf("%dԪ�ص�ǰ����%d\n", e, pre_e);
	}

	//9.�Һ��
   // NextElem(La,cur_e,&next_e);
	printf("������Ҫ���Һ�̵�Ԫ�أ�\n");
	scanf_s("%d", &e);
	if (NextElem(La, e, next_e))
	{
		printf("%dԪ�صĺ����%d\n", e, next_e);
	}
	
	//10.����
	// ListInsert(&La,i,e);
	
	printf("������Ҫ�����ֵ��");
	scanf_s("%d", &e);
	printf("�����뱻ǰ���Ԫ�أ�");
	scanf_s("%d", &inser_e);
	
	if (ListInsert(La,inser_e,e))
	{
		printf("����������Ϊ:\n");
		ListTraverse(La);
		printf("\n");
	}

	//11.ɾ��Ԫ��e
	// ListDelete(&La,i,&e);
	
	printf("������Ҫɾ����Ԫ�أ�\n");
	scanf_s("%d", &e);
	LNode* p;
	if (ListDelete(La,e))
	{
		ListTraverse(La);
		printf("\n��ɾ����\n");
	}
	
	//12.����
	printf("����˳�����\n");
	ListTraverse(La);

	printf("\n");

	//2.�������Ա�
	//DestroyList(&La)
	printf("���ٵ�������\n");
	if (DestroyList(La))
	{
		printf("�Ѿ����ٵ�������\n");
		return 0;
	}
	*/
	return 0;
}

void InputElement(LinkList & L)
{

	int element;
	int count;
	LinkList tail = L;
	printf("count=");
	scanf("%d", &count);
	printf("element=");
		for (int i = 0;i < count;i++)
	{
		scanf("%d", &element);
		LNode* newLNode = (LNode*)malloc(sizeof(LNode));
		newLNode->data = element;
		newLNode->next = NULL;
		ListInsert_back( L, tail,newLNode);
		tail = tail->next;//���¶�����βָ��
	}
}

void printf(ElemType& c)
{
	printf("%d ", c);
}

