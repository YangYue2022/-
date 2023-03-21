#include <stdio.h> 
#include <stdlib.h>
// 带头结点
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
// 初始化 
void InitQueue(LinkQueue& Q) {
	LinkNode* s=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front=Q.rear=s;
	Q.front->next=NULL;
}
// 判断为空
bool QueueEmpty(LinkQueue& Q) {
	return Q.front->next==NULL;
}
// 入队 - 只能在队尾插入 
bool EnQueue(LinkQueue& Q, int e) {
	LinkNode* s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=e;
	Q.rear->next=s;
	s->next=NULL;
	Q.rear=s;
	return true;
}
// 出队 - 只能在队头出 
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
// 读队头元素
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
// 打印
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
	if (QueueEmpty(Q)) printf("队列为空\n");
	EnQueue(Q, 1);
	printf("元素1入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 6);
	printf("元素6入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 7);
	printf("元素7入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 9);
	printf("元素9入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 11);
	printf("元素11入队后，队列大小：%d\n", GetSize(Q));
	PrintLiStack(Q);

	DeQueue(Q, e);
	printf("队头元素 %d 出队\n", e);
	PrintLiStack(Q);
	DeQueue(Q, e);
	printf("队头元素 %d 出队\n", e);
	PrintLiStack(Q);

	EnQueue(Q, 15);
	printf("元素15入队后，队列大小：%d\n", GetSize(Q));
	PrintLiStack(Q);

	DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e);
	if (QueueEmpty(Q)) {
		printf("所有元素出队，队列为空\n");
	}
	return 0;
}

