//带头结点的单链表
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,* LinkList;
// 单链表的建立
LNode* List_HeadInsert(LinkList& l) {// 头插法，建立逆序单链表 
	l=(LNode*)malloc(sizeof(LNode));
	LNode* s;
	int x;
	l->next=NULL;
	scanf("%d",&x);
	while(x!=0){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=l->next;
		l->next=s;
		scanf("%d",&x);
	}
	return l;
}
LNode* List_TailInsert(LinkList& l) {// 尾插法 
	l=(LNode*)malloc(sizeof(LNode));
	l->next=NULL;
	LNode* s;
	LNode* temp=l;
	int x;
	scanf("%d",&x);
	while(x!=0){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=NULL;
		temp->next=s;
		temp=s;
		scanf("%d",&x);
	}
	temp->next=NULL;
	return l;
}
// 按位序i查找结点，头结点的位序是0，1是第一个节点 
LNode* GetElem(LNode* l, int i) {
	if(i<0) return NULL;
	LNode* s=l;
	int j=0;
	while(j<i&&s!=NULL){
		j++;
		s=s->next;
	}
	return s;
}
// 按值e查找结点
LNode* LocateElem(LNode* l, int e) { 
	for(LNode* s=l->next;s!=NULL;s=s->next){
		if(s->data==e){
			return s;
		}
	}
	return NULL;
}
// 后插操作：在结点p后插入新节点-方法1
bool InsertNextNode(LNode* p, int e) {
	if(p==NULL) return false;
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s; 
	return true;
}
// 前插操作：在结点p之前插入元素e-方法2
bool InsertPriorNode(LNode* p, int e) {
	if(p==NULL) return false;
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->next=p->next;
	p->next=s;
	s->data=p->data;
	p->data=e;
	return true;
}
// 在位序i的位置插入结点操作
bool ListInsert(LNode* l, int i, int e) {
	LNode* s=GetElem(l,i-1);
	InsertNextNode(s,e);
}
// 在位序i的位置插入结点操作
bool ListInsertBefore(LNode* l, int i, int e) {
	LNode* s=GetElem(l,i);
	InsertPriorNode(s,e);
}
// 在位序i的位置删除结点操作-方法1
bool ListDelete(LNode* l, int i, int& e) {
	LNode* s=GetElem(l,i-1);
	if(s==NULL) return false;
	LNode* q=s->next;
	s->next=q->next;
	e=q->data;
	free(q);
	return true;
}
//  删除指定结点p, 不通过前驱节点操作，用交换数据那样删除，但是注意最后一个节点不能这样删除-方法2
bool DeleteZhidingLNode(LNode* p) {
	if(p==NULL||p->next==NULL) return false;
	LNode* s=p->next;
	p->data=s->data;
	p->next=s->next;
	free(s);
	return true;
}
// 在位序i的位置删除结点操作
bool ListDeleteZhiding(LNode* l, int i, int& e) {
	
	LNode* s=GetElem(l,i);
	if(s==NULL) return false;
	e=s->data;
	DeleteZhidingLNode(s);
	return true;
}
// 求表长
int Length(LNode* l) {
	int i=0;
	for(LNode* s=l;s->next!=NULL;s=s->next){
		i++;
	}
	return i;
}
// 链表输出
void PrintLinkList(LinkList& l) {
	printf("开始打印");
	LNode* p = l;
	while (p->next != NULL) {
		p = p->next;
		printf("%d\t", p->data);// 放后面因为头结点是没有值的 
	}
	printf("\n");
}
int main() {
	int e;
	// 实现操作
	LNode* L;
	printf("输入值建立链表，输入0结束\n");
	List_TailInsert(L);// 尾插
//	List_HeadInsert(L);// 头插
	PrintLinkList(L);
	// 两种插入方法测试，都是在i的位置插入节点 
	printf("在位序3的位置插入结点\n");
	ListInsert(L, 3, 33);		
	PrintLinkList(L);
	printf("在位序5的位置插入结点\n");
	ListInsertBefore(L, 5, 55); 
	PrintLinkList(L);
	// 两种删除方法测试
	printf("删除位序2的结点\n");
	ListDelete(L, 2, e);			// 通过前驱节点
	PrintLinkList(L);
	printf("删除位序4的结点\n");
	ListDeleteZhiding(L, 4, e);// 不通过前驱节点，通过交换数据方法 
	PrintLinkList(L);
}
 
