//ѭ��������-��ͷ���
 #include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
// ������Ľ���
LinkList List_TailInsert(LinkList& L) {// β�巨 
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
// ��λ��i���ҽ�㣬ͷ����λ����0��1�ǵ�һ���ڵ� 
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
// ��ֵe���ҽ��
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
// ��λ��i��λ�ò��������
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
// ��λ��i��λ��ɾ��������
bool ListDelete(LinkList& L, int i, int& e) {
	int length=Length(L);
	if(i<=0||i>length||L==NULL) return false;
	LNode* pre=GetElem(L,i-1);
	LNode*temp=pre->next;
	e=temp->data;
	pre->next=temp->next;
	free(temp); 
}
// �������-����һ����㶼����ѭ��������������
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
	printf("����ֵ������������0����\n");
	List_TailInsert(L);
	PrintLinkList(L);
	printf("��λ��3��λ�ò�����\n");
	ListInsert(L, 3, 58);
	PrintLinkList(L);
	printf("ɾ��λ��2�Ľ��\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("ͨ����2������������\n");
	PrintLinkList(L->next->next);
	printf("λ��Ϊ3�Ľ�㣺%d\n", GetElem(L, 3)->data);
}


