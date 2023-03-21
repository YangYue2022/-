#include <stdio.h> 
#include <stdlib.h>
// ��ͷ���
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
// ��ʼ�� 
void InitQueue(LinkQueue& Q) {
	LinkNode* s=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front=Q.rear=s;
	Q.front->next=NULL;
}
// �ж�Ϊ��
bool QueueEmpty(LinkQueue& Q) {
	return Q.front->next==NULL;
}
// ��� - ֻ���ڶ�β���� 
bool EnQueue(LinkQueue& Q, int e) {
	LinkNode* s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=e;
	Q.rear->next=s;
	s->next=NULL;
	Q.rear=s;
	return true;
}
// ���� - ֻ���ڶ�ͷ�� 
bool DeQueue(LinkQueue& Q, int& e) {
	if(QueueEmpty(Q)) return false;
	LinkNode* s=Q.front->next;
	e=s->data;
	Q.front->next=s->next;
	if(s==Q.rear){
		Q.rear=Q.front;
	}
	free(s);
	return true;
}
// ����ͷԪ��
bool GetHead(LinkQueue& Q, int& e) {
	if(QueueEmpty(Q)) return false;
	LinkNode* s=Q.front->next;
	e=s->data;
	return true;
}
int GetSize(LinkQueue& Q) {
	int size=0;
	LinkNode* s=Q.front->next;
	while(s!=NULL){
		size++;
		s=s->next;
	}
	return size;
}
// ��ӡ
void PrintLiStack(LinkQueue& Q) {
	LinkNode* s=Q.front->next;
	while(s!=NULL){
		printf("%d\t",s->data);
		s=s->next;
	}
	printf("\n"); 
}
int main()
{
	int e;
	bool b;
	LinkQueue Q;
	InitQueue(Q);
	if (QueueEmpty(Q)) printf("����Ϊ��\n");
	EnQueue(Q, 1);
	printf("Ԫ��1��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 6);
	printf("Ԫ��6��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 7);
	printf("Ԫ��7��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 9);
	printf("Ԫ��9��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 11);
	printf("Ԫ��11��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	PrintLiStack(Q);

	DeQueue(Q, e);
	printf("��ͷԪ�� %d ����\n", e);
	PrintLiStack(Q);
	DeQueue(Q, e);
	printf("��ͷԪ�� %d ����\n", e);
	PrintLiStack(Q);

	EnQueue(Q, 15);
	printf("Ԫ��15��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	PrintLiStack(Q);

	DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e);
	if (QueueEmpty(Q)) {
		printf("����Ԫ�س��ӣ�����Ϊ��\n");
	}
	return 0;
}

