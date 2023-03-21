//双链表-带头结点 
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;// 下一个
	struct LNode* prior;// 上一个
}LNode, * LinkList;
// 双链表的建立
LinkList List_TailInsert(LinkList& l) {// 尾插法 
	l=(LNode*)malloc(sizeof(LNode));
	l->prior=NULL;
	LNode*temp=l;
	int x;
	scanf("%d",&x);
	while(x!=0){
		LNode*s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->prior=temp;
		temp->next=s;
		temp=s;
		scanf("%d",&x);
	}
	temp->next=NULL;
	return l;
}
// 按位序i查找结点，头结点的位序是0，1是第一个节点 
LNode* GetElem(LinkList& L, int i) {
	LNode* s=L;
	int j=0;
	while(j<i&&s!=NULL){
		s=s->next;
		j++;
	}
	return s;
}
// 按值e查找结点
LNode* LocateElem(LinkList& L, int e) {
	LNode* s=L;
	while(s!=NULL){
		if(s->data==e){
			return s;
		}
		s=s->next;
	}
	return s;
}
//求表长 
int Length(LinkList& L) {
	int res=0;
	for(LNode* i=L->next;i!=NULL;i=i->next){
		res++;
	}
	return res;
}

// 在位序i的位置插入结点操作
bool ListInsert(LinkList& L, int i, int e) {
	int length=Length(L);
	if(i<1||i>length+1) return false; 
	

		LNode* s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
		LNode* pre=GetElem(L,i-1);

		LNode* next=pre->next;
		pre->next=s;
		s->prior=pre;
		s->next=next;
		if(next!=NULL){
			next->prior=s;
		}
		return true;
}
// 在位序i的位置删除结点操作
bool ListDelete(LinkList& L, int i, int& e) {
	int length=Length(L);
	if(i<1||i>length) return false;
	LNode* temp=GetElem(L,i);
	LNode* pre=temp->prior;
	LNode* next=temp->next;
	e=temp->data;
	pre->next=next;
	if(next!=NULL){
		next->prior=pre;
	}
	return true;
}
// 链表输出
void PrintLinkList(LinkList& L) {
	LNode* p = L->next;
	while (p != NULL) {
	
		printf("%d\t", p->data);
		p = p->next;	
	}
	printf("\n");
}
int main() {
	int e;
	// 实现操作
	LinkList L;
	printf("输入值建立链表，输入0结束\n");
	List_TailInsert(L);  // 输入链表值，输入0结束
	PrintLinkList(L);
	int x=Length(L);
	printf("链表长度:%d\n",x);
	printf("在位序3的位置插入结点\n");
	ListInsert(L, 3, 57);
	PrintLinkList(L);
	printf("删除位序2的结点\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	if (L->next->next->next != NULL) {
		printf("第3个结点的前驱节点是：%d\t", L->next->next->next->prior->data);
	}
}


