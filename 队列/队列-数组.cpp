#include <stdio.h> 
#include <stdlib.h>
#define MaxSize 5
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;
// 初始化 
void InitQueue(SqQueue& Q) {
	Q.front= Q.rear=0;
}
// 判断为空
bool QueueEmpty(SqQueue& Q) {
	return Q.rear=Q.front;
}
// 入队 - 只能在队尾插入 
bool EnQueue(SqQueue& Q, int e) {
	if((Q.rear+1)%MaxSize==Q.front){
		return false;
	}
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%MaxSize;
	return true;
}
// 出队 - 只能在队头出 
bool DeQueue(SqQueue& Q, int& e) {
	if(Q.rear==Q.front){
		return false;
	}
	e=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true;
}
// 读队头元素
bool GetHead(SqQueue& Q, int& e) {
	if(Q.rear==Q.front){
		return false;
	}
	e=Q.data[Q.front];
	return true;
}
int GetSize(SqQueue& Q) {
	return (Q.rear+MaxSize-Q.front)%MaxSize;
}
// 打印
void PrintSqQueue(SqQueue& Q) {
	if(Q.rear==Q.front){
		return;
	}
	for(int i=Q.front;i!=Q.rear;){
		printf("%d\t",Q.data[i]);
		i=(i+1)%MaxSize;
	}
	printf("\n");
}
int main()
{
	int e;
	bool b;
	SqQueue Q;
	InitQueue(Q);
	if (QueueEmpty(Q)) printf("队列为空\n");
	EnQueue(Q, 1);
	printf("元素1入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 3);
	printf("元素3入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 5);
	printf("元素5入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 9);
	printf("元素9入队后，队列大小：%d\n", GetSize(Q));
	PrintSqQueue(Q);

	b = EnQueue(Q, 10);
	if (!b) printf("因为牺牲了一个单元，队列已满, 插入10失败！\n");
	DeQueue(Q, e);
	printf("队头元素 %d 出队\n", e);
	EnQueue(Q, 10);
	printf("元素10入队后，队列大小：%d\n", GetSize(Q));
	PrintSqQueue(Q);

	DeQueue(Q, e); 
	printf("队头元素 %d 出队，队列大小：%d\n", e, GetSize(Q));
	PrintSqQueue(Q);

	EnQueue(Q, 12);
	printf("元素12入队后，队列大小：%d\n", GetSize(Q));
	PrintSqQueue(Q);

	DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e);
	if (QueueEmpty(Q)) {
		printf("所有元素出队，队列为空\n");
	}
	return 0;
}


