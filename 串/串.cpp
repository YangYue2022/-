#include <stdio.h>
#include <string.h>
#define MAXLEN 255
using namespace std;

//λ���0��ʼ
typedef struct{
	char ch[MAXLEN];
	int length;
}SString;

//��chars��ֵ���� 
bool StrAssign(SString& T,char *chars)
{ 
	if(strlen(chars)>MAXLEN)
		return false;
	else
	{
		T.length=strlen(chars);
		for(int i=0;i<T.length;i++){
			T.ch[i]=*(chars+i);
		}
		return true;
	}
}

//��ӡ 
void print(SString T){
	for(int i=0;i<T.length;i++){
		printf("%c\t",T.ch[i]);
	}
	printf("���ȣ�%d\n",T.length);
}

//����s���Ƶ���t 
bool StrCopy(SString& T,SString S)
{ 
	int i;
	for(i=0;i<S.length;i++)
		T.ch[i]=S.ch[i];
	return true;
}

//�ж��Ƿ�Ϊ��
bool StrEmpty(SString T){
	return T.length>0?0:1;
} 

//���
bool ClearString(SString& T){
	T.length=0;
	return true;
} 

//��T���������������� 
bool Concat(SString& T,char* s1,char*s2){
	if(strlen(s1)+strlen(s2)>MAXLEN){
		return false;
	}else{
		T.length=strlen(s1)+strlen(s2);
		int i;
		for(i=0;i<strlen(s1);i++){
			T.ch[i]=*(s1+i);
		}
		for(int j=0;i<T.length;i++){
			T.ch[i]=*(s2+j);
			j++; 
		}
		return true;
	}
	
}

//ȡ�Ӵ�
bool SubString(SString &Sub,SString S,int pos,int len)
{
	if(pos+len-1>S.length){
		return false;
	}else{
		for(int i=pos;i<pos+len;i++){
			Sub.ch[i-pos]=S.ch[i];
		}
		Sub.length=len;
		return true;
	}
}
 
//�Ƚϲ���
int StrCompare(SString s,SString t){
	for(int i=0;i<s.length&&i<t.length;i++){
		if(s.ch[i]!=t.ch[i]){
			return s.ch[i]-t.ch[i];
		}
	}
	return s.length-t.length;
} 

//�ҵ��Ӵ���λ��
int Index(SString s,SString t){
	int i=0;
	SString sub;
	while(i<=s.length-t.length){
		SubString(sub,s,i,t.length);
		if(StrCompare(sub,t)!=0){
			i++;
		}else{
			return i;
		}
	}
	return -1;
} 

//����ƥ��
int PsIndex(SString t,SString s){
	int k=0;
	int i=0,j=0;
	while(i<t.length&&j<s.length){
		if(t.ch[i]==s.ch[j]){
			i++;
			j++;
		}else{
			k++;
			i=k;
			j=0;
		}
	}
	if(j=s.length){
		return k;
	}
	else{
		return -1;
	}
} 

int main(){
	SString t;	
	StrAssign(t,"abcdaaabdef");
//	print(t);
	SString s;
	StrAssign(s,"abd");
	printf("%d",PsIndex(t,s));
//	printf("��123���Ƹ���\n"); 
//	StrCopy(t,s);
//	print(t);
//	printf("����123��abc��϶���\n"); 
//	Concat(t,"123","abc");
//	print(t);
//	printf("ȡ�Ӵ������±�2��ʼ������Ϊ3\n"); 
//	SubString(s,t,2,3);
//	print(s);
//	printf("�Ƚϴ�С��\n");
//	if(StrCompare(s,t)>0){
//		printf("�Ӵ���������");
//	}else if(StrCompare(s,t)==0){
//		printf("�Ӵ���������");
//	}else{
//		printf("�Ӵ�С������");
//	}
//	printf("\n");
//	printf("�ҵ��Ӵ���λ��:\n");
//	printf("%d\n",Index(t,s));
	return 0;
}

 
