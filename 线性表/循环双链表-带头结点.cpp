#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;// 下一个
	struct LNode* prior;// 上一个
}LNode, * LinkList;
// 循环双链表的建立
LinkList List_TailInsert(LinkList& L) {// 尾插法 
	L=(LNode*)malloc(sizeof(LNode));
	L->data=-1;
	LNode* temp=L;
	int x;
	scanf("%d",&x);
	while(x!=0){
		LNode* s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		temp->next=s;
		s->prior=temp;
		temp=s;
		scanf("%d",&x);
	}
	temp->next=L;
	L->prior=temp;
	return L;
}
//长度 
int Length(LinkList& l){
	LNode* s=l;
	int res=0;
	while(s->next!=l){
		res++;
		s=s->next;
	}
	
	return res;
	
}
// 按位序i查找结点，头结点的位序是0，1是第一个节点 
LNode* GetElem(LinkList& L, int i) {
	int length=Length(L);
	if(i<=0||i>length) return NULL;
	int j=0;
	LNode* s=L; 
	while(j<i){
		s=s->next;
		j++;
	} 
	return s;
}
// 按值e查找结点
LNode* LocateElem(LinkList& L, int e) {
	LNode* s=L;
	while(s!=L){
		if(s->data==e){
			return s;
		}
		s=s->next;
	}
	return NULL;
}
// 在位序i的位置插入结点操作
bool ListInsert(LinkList& L, int i, int e) {
	int length=Length(L);
	if(i<=0||i>length+1){
		return false;
	}
	LNode* pre=GetElem(L,i-1);
	LNode* nxt=pre->next;
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=nxt;
	pre->next=s;
	nxt->prior=s;
	s->prior=pre;
	return true;
}
// 在位序i的位置删除结点操作
bool ListDelete(LinkList& L, int i, int& e) {
	int length=Length(L);
	if(i<=0||i>length){
		return false;
	}
	LNode* pre=GetElem(L,i-1);
	LNode* temp=pre->next;
	LNode* nxt=temp->next;
	pre->next=nxt;
	nxt->prior=pre;
	free(temp);
	return true;
}
// 链表输出-任意一个结点都可以循环遍历整个链表
void PrintLinkList(LinkList& startNode) {
	LNode* s=startNode;
	do{
		if(s->data!=-1){
			printf("%d\t",s->data);
		}
		s=s->next;
	}while(s!=startNode);
	printf("\n");
}
int main() {
	int e;
	LinkList L;
	printf("输入值建立链表，输入0结束\n");
	List_TailInsert(L);
	int length=Length(L);
	printf("链表长度%d\n",length);
	PrintLinkList(L);
	printf("在位序3的位置插入结点\n");
	ListInsert(L, 3, 59);
	PrintLinkList(L);
	printf("删除位序2的结点\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("通过第3个结点遍历链表\n");
	PrintLinkList(L->next->next->next);
	if (L->next->next->next->next != NULL) {
		printf("第4个结点的前驱节点是%d\n", L->next->next->next->next->prior->data);
	}
}


