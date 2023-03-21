//˫����-��ͷ��� 
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;// ��һ��
	struct LNode* prior;// ��һ��
}LNode, * LinkList;
// ˫����Ľ���
LinkList List_TailInsert(LinkList& l) {// β�巨 
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
// ��λ��i���ҽ�㣬ͷ����λ����0��1�ǵ�һ���ڵ� 
LNode* GetElem(LinkList& L, int i) {
	LNode* s=L;
	int j=0;
	while(j<i&&s!=NULL){
		s=s->next;
		j++;
	}
	return s;
}
// ��ֵe���ҽ��
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
//��� 
int Length(LinkList& L) {
	int res=0;
	for(LNode* i=L->next;i!=NULL;i=i->next){
		res++;
	}
	return res;
}

// ��λ��i��λ�ò��������
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
// ��λ��i��λ��ɾ��������
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
// �������
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
	// ʵ�ֲ���
	LinkList L;
	printf("����ֵ������������0����\n");
	List_TailInsert(L);  // ��������ֵ������0����
	PrintLinkList(L);
	int x=Length(L);
	printf("������:%d\n",x);
	printf("��λ��3��λ�ò�����\n");
	ListInsert(L, 3, 57);
	PrintLinkList(L);
	printf("ɾ��λ��2�Ľ��\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	if (L->next->next->next != NULL) {
		printf("��3������ǰ���ڵ��ǣ�%d\t", L->next->next->next->prior->data);
	}
}


