#include <string.h>
#include <iostream>
#include <stack> 
using namespace std;

// �Ա������(��c1 >= c2 ����1�� �� c1 < c2 ����-1 ��
int CompareCal(char c1, char c2) {// c1��c2 ����������ٶ�ֻ��+-*/
	switch (c1) {
	case '+':case '-':
		if (c2 == '*' || c2 == '/')// ��+ -��С�ڡ�* /��
			return -1;
	}
	return 1;// Ĭ�ϴ���
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
// 1.��׺ת��׺���ʽ�����㷨 
string GenerateHou(stack<char>& opstack, string& s) {
	
	//�洢��׺���ʽ 
	string hous; 
	//�ֱ𴢴浱ǰ�ַ������ַ� �� �����ջ�е��ַ� 
	char curc,zhanc;
	
	for(int i=0;i<s.length();i++){
		curc=s[i];
		
		//1.������������ֱ�ӽ������ 
		if(isdigit(curc)){
			hous=hous+curc;
		}
		//2.��������ֱ��push 
		else if(curc=='('){
			opstack.push(curc); 
		}
		//3.��������ջԪ�ص����������֪�����������ţ�������ֻ������������� 
		else if(curc==')'){
			zhanc=opstack.top();
			opstack.pop();
			while(zhanc!='('){
				hous=hous+zhanc;
				zhanc=opstack.top();
				opstack.pop();
			}
		}
		//4.��������������
		//���ջΪ�գ�ֱ��Push
		//���ջ����(��ֱ��push
		//���ջ������������ж����ȼ������ȼ��߻���ͬ��pop�������ֱ���������ȼ��͵ģ���curc��ջ 
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
	
	// ��ջ��ʣ�µķ����׺���ʽ��
	while (!opstack.empty()) {
		zhanc = opstack.top();
		opstack.pop();
		hous = hous + zhanc;
	}
	return hous; 

}
// 2.��׺���ʽ���� 
int CalHou(stack<int>& distack, string& s) {
	int left,right;
	int sum;
	char curc;
	for(int i=0;i<s.length();i++){
		curc=s[i];
		if(isdigit(curc)){
			distack.push(curc-'0');//ת�������� 
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
	// ����Сȱ�㣺�����ֵ���ڵ���10�ͻ���� 
	
	// 1.���ɺ�׺���ʽ
	stack<char> opstack0;
	string s1 = "1+4*3+2";
	string s2 = GenerateHou(opstack0, s1);
	cout << "��׺���ʽ" << s1 << "ת����׺���ʽΪ��" << s2 << endl;
	// 2.�����׺���ʽ
	stack<int> distack0;
	int val = CalHou(distack0, s2);
	cout << "�����׺���ʽ" << s2 << "�ã�" << val << endl;
	return 0;
}


