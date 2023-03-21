//带头结点的单链表
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,* LinkList;

// 单链表的建立
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
		printf("%d ", p->data);// 放后面因为头结点是没有值的 
	}
	printf("\n");
}

//插入排序
void InsertSort(LinkList& l){
	if(Length(l)==0||Length(l)==1) return;
	LNode* lastSorted=l->next;
	LNode* cur=l->next->next;
	while(cur){ 
		if(cur->data>=lastSorted->data){    //如果当前的值大于前一个值，则说明已经排好序 
			lastSorted=cur;
			cur=cur->next;
		}else{  //需要重头找到要插入的位置 
			LNode* temp=l;
			while(temp->next->data<=cur->data){
				temp=temp->next;
			}
			
			LNode* s=cur; //用s存储当前cur
			cur=cur->next;  //cur后移 
			lastSorted->next=cur;
			
			//节点s要接在temp后面
			s->next= temp->next;
			temp->next=s;
						
			
		}
	} 
	
} 

int main() {
	int e;
	// 实现操作
	LNode* L;
	printf("输入值建立链表，输入0结束\n");
	List_TailInsert(L);// 尾插
	InsertSort(L);
	PrintLinkList(L);
	
}
 
