//循环单链表-带头结点
 #include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
// 单链表的建立
LinkList List_TailInsert(LinkList& L) {// 尾插法 
	L=(LNode*)malloc(sizeof(LNode));
	L->data=-1;
	LNode* temp=L;
	
	int x;
	scanf("%d",&x);
	while(x!=0){
		LNode* s= (LNode*)malloc(sizeof(LNode));
		s->data=x;
		temp->next=s;
		temp=s;
		scanf("%d",&x);
	}
	temp->next=L;
	return L;
}

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
	if(i<0||L==NULL||i>length) return NULL;
	LNode* s=L;
	int j=0;
	while(j<i){
		s=s->next;
		j++;
	}
	return s;
}
// 按值e查找结点
LNode* LocateElem(LinkList& L, int e) {
	LNode* s=L;
	while(s->next!=NULL){
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
	if(i<=0||i>length+1) return false;
	LNode* pre=GetElem(L,i-1);
	LNode* s= (LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=pre->next;
	pre->next=s;
	return true;
}
// 在位序i的位置删除结点操作
bool ListDelete(LinkList& L, int i, int& e) {
	int length=Length(L);
	if(i<=0||i>length||L==NULL) return false;
	LNode* pre=GetElem(L,i-1);
	LNode*temp=pre->next;
	e=temp->data;
	pre->next=temp->next;
	free(temp); 
}
// 链表输出-任意一个结点都可以循环遍历整个链表
void PrintLinkList(LinkList& startNode) {// 
	LNode* s=startNode;
	do{

		printf("%d\t",s->data);
		s=s->next;
	}while(s!=startNode);
	printf("\n");
}
int main() {
	int e;
	LinkList L;
	printf("输入值建立链表，输入0结束\n");
	List_TailInsert(L);
	PrintLinkList(L);
	printf("在位序3的位置插入结点\n");
	ListInsert(L, 3, 58);
	PrintLinkList(L);
	printf("删除位序2的结点\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("通过第2个结点遍历链表\n");
	PrintLinkList(L->next->next);
	printf("位序为3的结点：%d\n", GetElem(L, 3)->data);
}


