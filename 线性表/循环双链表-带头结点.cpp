#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;// ��һ��
	struct LNode* prior;// ��һ��
}LNode, * LinkList;
// ѭ��˫����Ľ���
LinkList List_TailInsert(LinkList& L) {// β�巨 
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
//���� 
int Length(LinkList& l){
	LNode* s=l;
	int res=0;
	while(s->next!=l){
		res++;
		s=s->next;
	}
	
	return res;
	
}
// ��λ��i���ҽ�㣬ͷ����λ����0��1�ǵ�һ���ڵ� 
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
// ��ֵe���ҽ��
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
// ��λ��i��λ�ò��������
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
// ��λ��i��λ��ɾ��������
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
// �������-����һ����㶼����ѭ��������������
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
	printf("����ֵ������������0����\n");
	List_TailInsert(L);
	int length=Length(L);
	printf("������%d\n",length);
	PrintLinkList(L);
	printf("��λ��3��λ�ò�����\n");
	ListInsert(L, 3, 59);
	PrintLinkList(L);
	printf("ɾ��λ��2�Ľ��\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("ͨ����3������������\n");
	PrintLinkList(L->next->next->next);
	if (L->next->next->next->next != NULL) {
		printf("��4������ǰ���ڵ���%d\n", L->next->next->next->next->prior->data);
	}
}


