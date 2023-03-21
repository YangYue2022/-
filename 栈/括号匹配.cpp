#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define MaxSize 50

typedef struct {
	char data[MaxSize];
	int top;
} SqStack;

// ≥ı ºªØ 
void InitStack(SqStack& stack) {
	stack.top = 0;
}
// »Î’ª
bool Push(SqStack& stack, char e) {
	if(stack.top==MaxSize){
		return false;
	}
	stack.data[stack.top++]=e;
//	printf("»Î’ª\n");
	return true;
}
// ≥ˆ’ª
bool Pop(SqStack& stack, char& e) {
	if(stack.top==0){
		return false;
	}
	e=stack.data[--stack.top];
	return true;
}
//  «∑ÒŒ™ø’
bool StackEmpty(SqStack& stack) {
	if (stack.top == 0) {
//		printf("empty\n");
		return true;
	}
	return false;
}
// ¥Ú”°
void PrintStack(SqStack& stack) {
	for(int i=0;i<stack.top;i++){
		printf("%d\t",stack.data[i]);
	}
	printf("\n");
	return;
}
// ¿®∫≈∆•≈‰
int MatchKuohao(SqStack& L, const char* s, int len) {
	char c = 0;
//	printf("%d\n",len);
	for (int i = 0; i < len; i++) {
		c = s[i];
		// 1.≈–∂œ «∑ÒŒ™◊Û¿®∫≈  «æÕ»Î’ª 
		if (c == '(' || c == '{' || c == '[') {
			Push(L, c);
		}
		else {
			// 2. «”“¿®∫≈£¨»°≥ˆ’ª∂•¿®∫≈”Î÷Æ∆•≈‰
			if (StackEmpty(L)) { // ≤ª¥Ê‘⁄◊Û¿®∫≈”Î÷Æ∆•≈‰£¨¥˙±Ì ß∞‹ 
				return 1;
			}
			Pop(L, c);
			// ≈–∂œ «∑Ò∆•≈‰ 
			if (s[i] == ')' && c != '('||s[i] == '}' && c != '{'||s[i] == ']' && c != '[') {
				return 2;
			
			}
		}
	}
	// 3.‘⁄≈–∂œ’ª «∑Ò”–◊Û¿®∫≈Œ¥∆•≈‰µƒ
	if (!StackEmpty(L)) {
		return 3;
	}
	return 0;
}
int main()
{
	SqStack L;
	// ¿®∫≈∆•≈‰ø™ º
	const char* s = "({()})";
	int b = MatchKuohao(L, s, strlen(s));
	printf("%s", s);
	if (b == 0) {
		printf("¿®∫≈∆•≈‰≥…π¶\n");
	}
	else if (b == 1) {
		printf("¿®∫≈∆•≈‰ ß∞‹, ”“¿®∫≈∂‡¡À\n");
	}
	else if (b == 2) {
		printf("¿®∫≈∆•≈‰ ß∞‹£¨◊Û”“¿®∫≈≤ª∆•≈‰\n");
	}
	else if (b == 3) {
		printf("¿®∫≈∆•≈‰ ß∞‹£¨ ◊Û¿®∫≈∂‡¡À\n");
	}
	return 0;
}


