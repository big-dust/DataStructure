#include "..\include\head.h"
using namespace std;


//初始化链表:带头结点的
LinkList InitList( ) {
	LinkList head = new Node;
	head->next = NULL;
	return head;
}

//销毁链表
Status DestroyList(LinkList &l) {
	if (l == NULL){
		return ERROR;
	}
	Node * p = l;
	Node * next;
	while(1){
		if (p == NULL){
			break;
		}
		next = p->next;		
		delete p;
		p = next;
	}
	l = NULL;
	return OK;
}

//重置链表
Status ClearList(LinkList &l) {
	if (l == NULL){
		return ERROR;
	}
	DestroyList(l->next);
	return OK;
}

//链表是否空
bool ListEmpty(LinkList l) {
	if (l->next==NULL){
		return true;
	}
	return false;
}

//链表长度
int ListLength(LinkList l) {
	int length = 0;
	Node * p = l->next;
	while(p!=NULL){
		length++;
		p = p->next;
	}
	return length;
}

//获取指定位置元素
bool GetElem(LinkList l, int j, ElemType &e) {
	if (j<1 || j> ListLength(l)){
		return false;
	}

	int i = 1;
	Node * p = l->next;
	while(j!=i){
		i++;
		p = p->next;
	}
	e = p->data;

	return true;
}

//定位元素
int LocateElem(LinkList l, ElemType e) {
	int location = 1;
	Node * p = l->next;

	while(p!=NULL){
		if (p->data == e){
			return location;
		}
		location++;
		p = p->next;
	}
	
	return 0;
}

//前驱
Status PriorElem(LinkList l, int cur_e, ElemType &pre_e) {
	if (cur_e < 2 || cur_e > ListLength(l)){
		return ERROR;
	}

	if (!GetElem(l,cur_e-1,pre_e)){
		return false;
	}

	return true;
}

//后继
Status NextElem( LinkList l, int cur_e, ElemType &next_e) {
	if (cur_e < 1 || cur_e > ListLength(l)+1){
		return ERROR;
	}

	if (!GetElem(l,cur_e+1,next_e)){
		return false;
	}

	return true;
}

//前插
Status ListInsert_front(LinkList &l, Node*p, Node*s) {
	if ( l== NULL ){
		return ERROR;
	}
	Node * q = l;
	while(q->next != NULL && q->next != p ){
		q = q->next;
	}
	if (q->next == NULL){
		cout<<"ListInsert_front: 没有指定的元素"<<endl;
		return ERROR;
	}
	s->next = q->next;
	q->next = s;
	return OK;
}

//后插
Status ListInsert_back(LinkList& l, Node* p, Node* s) {
	if ( l== NULL ){
		return ERROR;
	}
	Node * q = l->next;
	while(q != NULL && q != p){
		q = q->next;
	}
	if (q == NULL){
		cout<<"ListInsert_back: 没有指定的元素"<<endl;
		return ERROR;
	}
	s->next = q->next;
	q->next = s;
	return OK;
}

//删链表
Status ListDelete(LinkList &l, Node *p, ElemType &e) {
	Node * q = l;
	while(q->next != NULL && q->next != p){
		q = q->next;
	}
	if (q->next == NULL){
		cout<<"ListInsertDelete: 没有指定的的节点"<<endl;
		return ERROR;
	}
	Node * tmp = q->next;
	q->next = tmp->next;
	delete tmp;
	return OK;
}

//遍历打印
Status ListTraverse(LinkList& l) {
	Node* p = l->next;
	while (p) {
		printf("%d ", p->data);
		p=p->next;
	}
	return OK;
}

//输入元素
void InputElement(LinkList& l)
{
	cout<<"元素个数: ";
	int num;
	cin>>num;
	ElemType tmp;
	Node * p = l;
	cout<<"输入"<<num<<"个"<<"元素: ";
	while(num--){
		cin>>tmp;
		Node * node = new Node;
		node->data = tmp;
		node->next=NULL;
		p->next=node;
		p = p->next;
	}
	cout<<"输入完成"<<endl;
}


void print(ElemType& c)
{
	printf("%d ", c);
}