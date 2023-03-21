//��ͷ���ĵ�����
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,* LinkList;
// ������Ľ���
LNode* List_HeadInsert(LinkList& l) {// ͷ�巨�������������� 
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
LNode* List_TailInsert(LinkList& l) {// β�巨 
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
// ��λ��i���ҽ�㣬ͷ����λ����0��1�ǵ�һ���ڵ� 
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
// ��ֵe���ҽ��
LNode* LocateElem(LNode* l, int e) { 
	for(LNode* s=l->next;s!=NULL;s=s->next){
		if(s->data==e){
			return s;
		}
	}
	return NULL;
}
// ���������ڽ��p������½ڵ�-����1
bool InsertNextNode(LNode* p, int e) {
	if(p==NULL) return false;
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s; 
	return true;
}
// ǰ��������ڽ��p֮ǰ����Ԫ��e-����2
bool InsertPriorNode(LNode* p, int e) {
	if(p==NULL) return false;
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->next=p->next;
	p->next=s;
	s->data=p->data;
	p->data=e;
	return true;
}
// ��λ��i��λ�ò��������
bool ListInsert(LNode* l, int i, int e) {
	LNode* s=GetElem(l,i-1);
	InsertNextNode(s,e);
}
// ��λ��i��λ�ò��������
bool ListInsertBefore(LNode* l, int i, int e) {
	LNode* s=GetElem(l,i);
	InsertPriorNode(s,e);
}
// ��λ��i��λ��ɾ��������-����1
bool ListDelete(LNode* l, int i, int& e) {
	LNode* s=GetElem(l,i-1);
	if(s==NULL) return false;
	LNode* q=s->next;
	s->next=q->next;
	e=q->data;
	free(q);
	return true;
}
//  ɾ��ָ�����p, ��ͨ��ǰ���ڵ�������ý�����������ɾ��������ע�����һ���ڵ㲻������ɾ��-����2
bool DeleteZhidingLNode(LNode* p) {
	if(p==NULL||p->next==NULL) return false;
	LNode* s=p->next;
	p->data=s->data;
	p->next=s->next;
	free(s);
	return true;
}
// ��λ��i��λ��ɾ��������
bool ListDeleteZhiding(LNode* l, int i, int& e) {
	
	LNode* s=GetElem(l,i);
	if(s==NULL) return false;
	e=s->data;
	DeleteZhidingLNode(s);
	return true;
}
// ���
int Length(LNode* l) {
	int i=0;
	for(LNode* s=l;s->next!=NULL;s=s->next){
		i++;
	}
	return i;
}
// �������
void PrintLinkList(LinkList& l) {
	printf("��ʼ��ӡ");
	LNode* p = l;
	while (p->next != NULL) {
		p = p->next;
		printf("%d\t", p->data);// �ź�����Ϊͷ�����û��ֵ�� 
	}
	printf("\n");
}
int main() {
	int e;
	// ʵ�ֲ���
	LNode* L;
	printf("����ֵ������������0����\n");
	List_TailInsert(L);// β��
//	List_HeadInsert(L);// ͷ��
	PrintLinkList(L);
	// ���ֲ��뷽�����ԣ�������i��λ�ò���ڵ� 
	printf("��λ��3��λ�ò�����\n");
	ListInsert(L, 3, 33);		
	PrintLinkList(L);
	printf("��λ��5��λ�ò�����\n");
	ListInsertBefore(L, 5, 55); 
	PrintLinkList(L);
	// ����ɾ����������
	printf("ɾ��λ��2�Ľ��\n");
	ListDelete(L, 2, e);			// ͨ��ǰ���ڵ�
	PrintLinkList(L);
	printf("ɾ��λ��4�Ľ��\n");
	ListDeleteZhiding(L, 4, e);// ��ͨ��ǰ���ڵ㣬ͨ���������ݷ��� 
	PrintLinkList(L);
}
 
