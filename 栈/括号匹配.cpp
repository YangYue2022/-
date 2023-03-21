#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define MaxSize 50

typedef struct {
	char data[MaxSize];
	int top;
} SqStack;

// ��ʼ�� 
void InitStack(SqStack& stack) {
	stack.top = 0;
}
// ��ջ
bool Push(SqStack& stack, char e) {
	if(stack.top==MaxSize){
		return false;
	}
	stack.data[stack.top++]=e;
//	printf("��ջ\n");
	return true;
}
// ��ջ
bool Pop(SqStack& stack, char& e) {
	if(stack.top==0){
		return false;
	}
	e=stack.data[--stack.top];
	return true;
}
// �Ƿ�Ϊ��
bool StackEmpty(SqStack& stack) {
	if (stack.top == 0) {
//		printf("empty\n");
		return true;
	}
	return false;
}
// ��ӡ
void PrintStack(SqStack& stack) {
	for(int i=0;i<stack.top;i++){
		printf("%d\t",stack.data[i]);
	}
	printf("\n");
	return;
}
// ����ƥ��
int MatchKuohao(SqStack& L, const char* s, int len) {
	char c = 0;
//	printf("%d\n",len);
	for (int i = 0; i < len; i++) {
		c = s[i];
		// 1.�ж��Ƿ�Ϊ������ �Ǿ���ջ 
		if (c == '(' || c == '{' || c == '[') {
			Push(L, c);
		}
		else {
			// 2.�������ţ�ȡ��ջ��������֮ƥ��
			if (StackEmpty(L)) { // ��������������֮ƥ�䣬����ʧ�� 
				return 1;
			}
			Pop(L, c);
			// �ж��Ƿ�ƥ�� 
			if (s[i] == ')' && c != '('||s[i] == '}' && c != '{'||s[i] == ']' && c != '[') {
				return 2;
			
			}
		}
	}
	// 3.���ж�ջ�Ƿ���������δƥ���
	if (!StackEmpty(L)) {
		return 3;
	}
	return 0;
}
int main()
{
	SqStack L;
	// ����ƥ�俪ʼ
	const char* s = "({()})";
	int b = MatchKuohao(L, s, strlen(s));
	printf("%s", s);
	if (b == 0) {
		printf("����ƥ��ɹ�\n");
	}
	else if (b == 1) {
		printf("����ƥ��ʧ��, �����Ŷ���\n");
	}
	else if (b == 2) {
		printf("����ƥ��ʧ�ܣ��������Ų�ƥ��\n");
	}
	else if (b == 3) {
		printf("����ƥ��ʧ�ܣ� �����Ŷ���\n");
	}
	return 0;
}


