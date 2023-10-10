#include "..\exam3_wjx\include\head.h"
using namespace std;

void ErrorMessage(const char *s)//出错信息处理函数 
{
	cout<<s<<endl;
	exit(1);
}

//初始化操作
Status InitList(SqList& l,int maxsize,int incresize) {
	l.elem = new ElemType[maxsize];
	l.length = 0;
	l.listsize = maxsize;
	l.incrementsize = incresize;
	return OK;
}

//销毁顺序表
Status DestroyList(SqList &l) {
	if (l.elem != nullptr) {
		delete[] l.elem;
	}
	l.length = 0;
	l.listsize = 0;
	return OK;
}

//重置为空表
Status ClearList(SqList& l) {
	l.length = 0;
	return OK;
}

//检查是否为空
Boolean ListEmpty(SqList l) {
	if (l.length == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//求长度
int ListLength(SqList l) {
	return l.length;
}

//找元素
Status GetElem(SqList l, int i, ElemType& e) {
	if (i < 1 || i > l.length) {
		return FALSE;
	}
	e = l.elem[i - 1]; 
	return TRUE;
}

//定位元素
int LocateElem(SqList l, ElemType e) {
	int i = 1;
	ElemType* p = l.elem;
	while (*p != e && l.length != 0) {
		++i;
		p++;
	}
	if (i <= l.length) {
		return i;
	}
	else {
		return 0;
	}
}

//找前驱
Status PriorElem(SqList l, ElemType cur_e, ElemType& pre_e) { 
	for (int i = 0; i < l.length; i++) { 
		if (l.elem[i] == cur_e && i > 0) { 
			//用pre_e返回它的前驱 
			pre_e = l.elem[i - 1];
			//返回成功 
			return OK; 
		}
	} //如果没有找到cur_e或者是第一个元素，返回失败 
		return ERROR; 
}

//找后驱
Status NextElem(SqList l, ElemType cur_e, ElemType& next_e) {
	for (int i = 0; i < l.length; i++) {
		if (l.elem[i] == cur_e && i < l.length-1) {
			//用pre_e返回它的前驱 
			next_e= l.elem[i + 1];
			//返回成功 
			return OK; 
		}
	} //如果没有找到cur_e或者是第一个元素，返回失败 
	return ERROR;
}

//插入元素
void increment(SqList& l) {
	ElemType* a = new ElemType[l.listsize + l.incrementsize];
	for (int i = 0; i < l.length; i++) {
		a[i] = l.elem[i];
	}
	delete[] l.elem;
	l.elem = a;
	l.listsize += l.incrementsize;

}

Status InsertElem(SqList &l, int i, ElemType e){
	ElemType* p;
	ElemType* q;
	if (i<1 || i>l.length + 1) {
		ErrorMessage("i值不合法");
	}
	if (l.length >= l.listsize) {
		increment(l);
	}
		
	q = &(l.elem[i - 1]);

	for (p = &(l.elem[l.length - 1]); p >= q; --p) {
		*(p + 1) = *p;
	}
	*q = e;
	++l.length;
	return OK;
}


//删除元素
Status ListDelete(SqList& l, int i, ElemType& e) {
	if (i<1 || i>l.length) {
		ErrorMessage("i值不合法");
	}
	ElemType* p = &(l.elem[i - 1]);
	e = *p;
	ElemType* q = l.elem + l.length - 1;
	p = p + 1;//下一个元素
	while (p < q) {
		*p = *(p + 1);//全部向前移动
		p++;
	}
	l.length -= 1;
	return OK;
}

//依次输出所有元素
Status ListTraverse(SqList l) {
	for (int i = 0; i < l.length; i++) {
		printf("%d", l.elem[i]);
	}
	return OK;
}

