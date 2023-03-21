#include <stdio.h> 
#define MaxSize 50

typedef struct {
	int data[MaxSize];
	int top;
} SqStack;
// 初始化 
void InitStack(SqStack& stack) {
	stack.top = 0;
}
// 是否为空 
bool StackEmpty(SqStack& stack) {
	if (stack.top == 0) {
		return true;
	}
	return false;
}
// 入栈 
bool Push(SqStack& stack, int e) {
	if(stack.top==MaxSize){
		return false;
	}
	stack.data[stack.top++]=e;
	return true;
}
// 出栈 
bool Pop(SqStack& stack, int& e) {
	if(stack.top==0){
		return false;
	}
	e=stack.data[--stack.top];
	return true;
}
// 获取栈顶 
bool GetTop(SqStack& stack, int& e) {
	if(stack.top==0){
		return false;
	}
	e=stack.data[stack.top-1];
	return true;
}
// 遍历
void PrintStack(SqStack& stack) {
	for(int i=0;i<stack.top;i++){
		printf("%d\t",stack.data[i]);
	}
	printf("\n");
	return;
}
int main()
{
	int e;
	bool b;
	SqStack stack;
	InitStack(stack);// 初始化
	printf("栈是否为空：%d\n", StackEmpty(stack));
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);
	printf("元素压入栈后：\n");
	PrintStack(stack);
	b = Pop(stack, e);
	if (b) printf("出栈元素：%d\n", e); 
	b = GetTop(stack, e);
	if (b) printf("栈顶元素是：%d\n", e);
	Push(stack, 7);
	printf("元素7压入栈后：\n");
	PrintStack(stack);
	return 0;
}


