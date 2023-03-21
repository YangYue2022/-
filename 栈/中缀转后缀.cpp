#include <string.h>
#include <iostream>
#include <stack> 
using namespace std;

// 对比运算符(当c1 >= c2 返回1， 当 c1 < c2 返回-1 ）
int CompareCal(char c1, char c2) {// c1，c2 是运算符，假定只有+-*/
	switch (c1) {
	case '+':case '-':
		if (c2 == '*' || c2 == '/')// “+ -”小于“* /”
			return -1;
	}
	return 1;// 默认大于
}
int Cal(int val1, char op, int val2) {
	switch (op) {
	case '+':
		return val1 + val2;
	case '-':
		return val1 - val2;
	case '*':
		return val1 * val2;
	case '/':
		return val1 / val2;
	}
	return 0;
}
// 1.中缀转后缀表达式生成算法 
string GenerateHou(stack<char>& opstack, string& s) {
	
	//存储后缀表达式 
	string hous; 
	//分别储存当前字符串的字符 、 运算符栈中的字符 
	char curc,zhanc;
	
	for(int i=0;i<s.length();i++){
		curc=s[i];
		
		//1.遇到操作数，直接将它输出 
		if(isdigit(curc)){
			hous=hous+curc;
		}
		//2.遇到（，直接push 
		else if(curc=='('){
			opstack.push(curc); 
		}
		//3.遇到），栈元素弹出并输出，知道遇到左括号（左括号只弹出，不输出） 
		else if(curc==')'){
			zhanc=opstack.top();
			opstack.pop();
			while(zhanc!='('){
				hous=hous+zhanc;
				zhanc=opstack.top();
				opstack.pop();
			}
		}
		//4.其他运算符的情况
		//如果栈为空，直接Push
		//如果栈顶是(，直接push
		//如果栈顶是运算符，判断优先级，优先级高或相同的pop并输出，直到遇到优先级低的，将curc入栈 
		else{
			while(!opstack.empty()){
				zhanc=opstack.top();
				if(zhanc=='('){
					break;
				}
				if(CompareCal(zhanc,curc)==1){
					hous=hous+zhanc;
					opstack.pop();
				}
				else{
					break;
				}
			}
			opstack.push(curc);
		}
	}
	
	// 把栈中剩下的放入后缀表达式中
	while (!opstack.empty()) {
		zhanc = opstack.top();
		opstack.pop();
		hous = hous + zhanc;
	}
	return hous; 

}
// 2.后缀表达式计算 
int CalHou(stack<int>& distack, string& s) {
	int left,right;
	int sum;
	char curc;
	for(int i=0;i<s.length();i++){
		curc=s[i];
		if(isdigit(curc)){
			distack.push(curc-'0');//转换成数字 
		}else{
			left=distack.top();
			distack.pop();
			right=distack.top();
			distack.pop();
			sum=Cal(left,curc,right);
			distack.push(sum);
		}
	}
	return sum;
}
int main()
{
	// 程序小缺点：如果数值大于等于10就会算错。 
	
	// 1.生成后缀表达式
	stack<char> opstack0;
	string s1 = "1+4*3+2";
	string s2 = GenerateHou(opstack0, s1);
	cout << "中缀表达式" << s1 << "转换后缀表达式为：" << s2 << endl;
	// 2.计算后缀表达式
	stack<int> distack0;
	int val = CalHou(distack0, s2);
	cout << "计算后缀表达式" << s2 << "得：" << val << endl;
	return 0;
}


