//����ͷ������ 
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
} LNode, * LinkList;
// ������
LinkList List_TailInsert(LinkList& L) {// β�巨
	L=(LNode*)malloc(sizeof(LNode));
	LNode *s=L,*t=NULL;
	L->next=NULL;
	int x;
	scanf("%d",&x);
	while(x!=0){
		//s���½ڵ㣬t��β�ڵ� 
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
// ��λ��i���ҽ�㣬1�ǵ�һ���ڵ� 
LNode* GetElem(LinkList& L, int i) {
	if (i <= 0) {
		return NULL;
	}
	int j = 1;					// // ע�⣺����ͷ����1��ʼ����Ԫ����λ��Ϊ1
	LNode* p = L;				// ͷ��㿪ʼ 
	while (p != NULL && j < i) {	// ����Ѱ�� 
		p = p->next;
		j++;
	}
	return p;

}
// ��λ��i��λ�ò��������
bool ListInsert(LinkList& L, int i, int e) {
	if(i<1) return false;
	else if(i==1){ //����ڱ�ͷ����ڵ� 
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
// ��λ��i��λ��ɾ��������
bool ListDelete(LinkList& L, int i, int& e) {
	
	if(i<1) return false;
	
	//ɾ����һ���ڵ�
	if(i==1){
		LNode* temp=L;
		L=L->next;
		free(temp);
	}
	
	//ɾ������Ľڵ�
	LNode* temp= GetElem(L,i-1);
	if(temp==NULL) return false;
	LNode*q=temp->next;
	temp->next=q->next;
	free(q);
	return true;
	
}
// ���
int Length(LinkList& L) {
	int res=0;
	for(LNode* i=L;i!=NULL;i=i->next){
		res++;
	}
	return res;
}
// �������
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
	printf("����ֵ������������0����\n");
	List_TailInsert(L);
	PrintLinkList(L);
	printf("��λ��3��λ�ò�����\n");
	ListInsert(L, 3, 53);
	PrintLinkList(L);
	printf("ɾ��λ��2�Ľ��\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("����%d\t", Length(L));
	return 0;
}

