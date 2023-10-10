#include"..\include\head.h"
using namespace std;
void ErrorMessage(const char* s)//������Ϣ�������� 
{
	cout << s << endl;
	exit(1);
}


void incremensize(LNode & L);
//**********��������12����������***********

//����InitList
Status InitList(LinkList &L)
{
	 L = (LNode*)malloc(sizeof(LNode));//��̬����
	if (L != NULL)
	{
		L->next = NULL;
	}
	return OK;
}


//����DestroyList
Status DestroyList(LinkList& L)
{
	LNode* p;
	p = L;//pָ��ͷָ��
	while (L->next != NULL)//���ͷָ��ָ��ĺ�̲�Ϊ�գ�ѭ��
	{
		L = L->next;//ͷָ���̳�Ϊ�µ�ͷָ��
		free(p);//�ͷ�p
		p = L;//pָ���µ�ͷָ��
	}
	return OK;
}


// ����ClearList
Status ClearList(LinkList& L)
{
	LNode* p, * q;
	p = L->next;//pָ��ͷָ����
	while (p)
	{
		q = p->next;//qָ��p�ĺ��
		free(p);//�ͷ�p
		p = q;//pָ��q
	}
	L->next = NULL;//�γɿձ�
	return OK;
}

// �ж�ListEmpty
Status ListEmpty(LinkList L)
{
	if (L->next == NULL)//���ͷָ����Ϊ�գ���Ϊ��
	{
		return TRUE;
	}
	else
		return FALSE;
}

// ����ListLength
Status ListLength(LinkList L) 
{
	//�����Ƿ����ͷָ��
	//LΪ����ͷָ�룬����������L��ָ����������
	LNode * p; int k=0;//pΪָ�룬k���ڼ���
	p = L;
	while (p)
	{
		p=p->next;
		k++;
	}
	return k;
}

// ��λGetElem
Status GetElem(LinkList L, ElemType i, ElemType& e)
{
	//����������i��Ԫ�ص�ֵ
	LNode* p;
	p = L;
	if (i < 0)//����i���Ϸ�
		return ERROR;
	else {
		for (int j = 1;j <= i;j++)
		{
			p = p->next;//��pָ��Ҫ���ҵ�λ��
		}

		e = p->data;
	}
	return OK;
	
}

//����LocateElem
int LocateElem(LinkList L, ElemType e)
{
	int Location = 0;
	//���������ҵ���һ����eԪ����ͬ��Ԫ��
	LNode* p;
	p = L;
	while (p&&p->data != e)
	{
		p = p ->next;
		Location++;
	}
	return Location;

}

//ǰ��PriorElem
Status PriorElem(LinkList L, ElemType cur_e, ElemType& pre_e)
{
	LNode* p;LNode*pre;
	int i = 0;
	p = L->next;
	pre = L;

	while (p!=NULL)
	{
		if (p->data == cur_e)
		{
			if (pre != L)
			{
				pre_e = pre->data;
				return OK;
			}

			else return ERROR;
		}
			p = p->next;
			pre = pre->next;//p��preͬʱ�ƶ���preʼ��Ϊpǰ��
			
		
	}
	
}

// ���NextElem
Status NextElem(LinkList L, ElemType cur_e, ElemType& next_e)
{
	LNode* p;
	p = L->next;
	while (p != NULL&&p->data != cur_e) p = p->next;
	if (p == NULL || p->next == NULL)
	{
		return ERROR;//�����ں��
	}
	next_e = p->next->data;
	return OK;
}

//����ListInsertǰ��
Status ListInsert(LinkList& L,ElemType inser_e,ElemType e)
{
	//pΪ����λ��ָ�룬sΪ�²���ָ��
	LNode* p;
	LNode* s;
	p = L;
	while (p->data != inser_e)p = p->next;
	s = new LNode;
	s->data = e;
	//ָ��pָ��LΪͷָ��������е�ĳ���ڵ㣬��s�����뵽p���֮ǰ
	if (p == L)
	{
		s->next = L;
		s = L;
	}
	else {
		LNode* q;
		q = L;//��q������p��ǰ��
		while (q->next != p) q=q->next;//q����pǰ��������һλ
		q->next = s;
		s->next = p;//����
	}
	return OK;
}

Status ListInsert_back(LinkList L, LNode* p,LNode *s)
{
	//ָ��pָ��LΪͷָ��������е�ĳ���ڵ㣬��s�����뵽p���֮��
	if ( p == NULL || s == NULL)
	{
		return ERROR;
	}
	else {
		LNode * tmp = new LNode;
		tmp->data = s->data;
		tmp->next = NULL;
		tmp->next = p->next;
		p->next = tmp;
		
	}
	return OK;
	
}

/*void back(int i, LinkList l) {
	if (l == NULL) {
		return;
	}
	LNode* p = l;

}*/
//ɾ��ListDelete
Status ListDelete(LinkList& L, ElemType& e)
{
	LNode* p = L;
	while (p->data != e)p = p->next;
	//pָ��LΪͷָ���������ĳ��㣬��������ɾ���ý�㲢����e���ظ�ֵ
	if (p == L)//���ɾ����һ����㣬�ı�ͷָ��
	{
		L=p->next ;
	}
	else {
		LNode* q;
		q = L;//��q������p��ǰ��
		while (q->next != p) q = q->next;
		q->next = p->next;

	}
	e = p->data;free(p);
	return OK;
	
}

  //���ListTraverse
//遍历打印
Status ListTraverse(LinkList& l) {
	LNode* p = l->next;
	while (p) {
		printf("%d ", p->data);
		p=p->next;
	}
	return OK;
}

//AnB
LinkList Intersection(LinkList LA, LinkList LB)
{
	LNode* pa, * pb, * pc;//
	LinkList LC = (LNode*)malloc(sizeof(LNode));
	pa = LA->next;
	pb = LB->next;
	pc = LC;
	int flag = 0;
	while (pa != NULL)
	{
		while (pb != NULL)
		{
			if (pa->data == pb->data)
			{
				flag = 1;break;
			}
			pb = pb->next;
		}
		if (flag == 1)
		{
			ListInsert_back(LC, pc, pa);
			pc = pc->next;

		}
		pa = pa->next;
		pb = LB->next;
	}
	
	return LC;
}
//AUB
LinkList Union(LinkList LA, LinkList LB)
{
	LNode* pa, * pb, * pc;
	LinkList LC = (LNode*)malloc(sizeof(LNode));
	pa = LA->next;
	pb = LB->next;
	pc = LC; //
	int flag = 0;
	ListInsert_back(LC, pc, pa);
	while (pc->next != NULL)pc = pc->next;
	while(pb != NULL){
		if (LocateElem(LC,pb->data)==0){
			ListInsert_back(LC, pc, pb);
			pc = pc->next;
		}
		pb = pb->next;
	}

	// LNode* r = LC->next;
	// int location = LocateElem(LC,r->data );
	// while (location != 0)
	// {
	// 	ListDelete(LC, r->data);
	// 	r = r->next;
	// }
	
	return LC;
}

//A-B
LinkList Minus(LinkList LA, LinkList LB) {
	LinkList LC = (LNode*)malloc(sizeof(LNode));
	LC->next = NULL;
	LNode* s, *pc,* pb;
	pc = LC->next;
	pb = LB->next;
	int flag = 0;
	s = LC->next;
	for (LNode*p=LA->next;p!=NULL;p=p->next)
	{
		ListInsert_back(LC,p,s);
		s = s->next;
	}
	while (pc != NULL)
	{
		while (pb!= NULL)
		{
			if (pc->data == pb->data)//������ͬԪ�أ����
			{
				flag = 1;break;
			}
			pb = pb->next;
		}
		if (flag == 1)
		{
			ListDelete(LC, pc->data);

		}
		pc = pc->next;
	}
	return LC;
}