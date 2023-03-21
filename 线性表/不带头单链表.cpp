//不带头单链表 
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
} LNode, * LinkList;
// 链表建立
LinkList List_TailInsert(LinkList& L) {// 尾插法
	L=(LNode*)malloc(sizeof(LNode));
	LNode *s=L,*t=NULL;
	L->next=NULL;
	int x;
	scanf("%d",&x);
	while(x!=0){
		//s是新节点，t是尾节点 
		s->data=x;
		if(t!=NULL){  
			t->next=s;
		}
		t=s;
		scanf("%d",&x);
		s=(LNode*)malloc(sizeof(LNode*));
	}
	t->next=NULL;
	return L;
}
// 按位序i查找结点，1是第一个节点 
LNode* GetElem(LinkList& L, int i) {
	if (i <= 0) {
		return NULL;
	}
	int j = 1;					// // 注意：不带头结点从1开始，首元结点的位序为1
	LNode* p = L;				// 头结点开始 
	while (p != NULL && j < i) {	// 依次寻找 
		p = p->next;
		j++;
	}
	return p;

}
// 在位序i的位置插入结点操作
bool ListInsert(LinkList& L, int i, int e) {
	if(i<1) return false;
	else if(i==1){ //如果在表头插入节点 
		LNode* s=(LNode*)malloc(sizeof(LNode*));
		s->data=e;
		s->next=L->next;
		L=s;
		
	}
	else{
		LNode* s=GetElem(L,i-1);
		LNode* p=(LNode*)malloc(sizeof(LNode*));
		p->data=e;
		p->next=s->next;
		s->next=p;
	
	}
	return true;
	
}
// 在位序i的位置删除结点操作
bool ListDelete(LinkList& L, int i, int& e) {
	
	if(i<1) return false;
	
	//删除第一个节点
	if(i==1){
		LNode* temp=L;
		L=L->next;
		free(temp);
	}
	
	//删除后面的节点
	LNode* temp= GetElem(L,i-1);
	if(temp==NULL) return false;
	LNode*q=temp->next;
	temp->next=q->next;
	free(q);
	return true;
	
}
// 求表长
int Length(LinkList& L) {
	int res=0;
	for(LNode* i=L;i!=NULL;i=i->next){
		res++;
	}
	return res;
}
// 链表输出
void PrintLinkList(LinkList& L) {
	LNode* p = L;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	int e;
	LinkList L;
	printf("输入值建立链表，输入0结束\n");
	List_TailInsert(L);
	PrintLinkList(L);
	printf("在位序3的位置插入结点\n");
	ListInsert(L, 3, 53);
	PrintLinkList(L);
	printf("删除位序2的结点\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("表长：%d\t", Length(L));
	return 0;
}

