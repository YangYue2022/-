#include<stdio.h>
using namespace std;

//��С�������� 
//���鴫�α����Ͼ����˻�Ϊָ�봫�Σ�����ʵ���ݽ����޸� 
void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

//��ӡ
void print(int a[],int size){
	for(int i=0;i<size;i++){
		printf("%d ",a[i]);
	}
} 

//��ѡ������
void SelectSort(int a[],int size){
	for(int i=0;i<size-1;i++){  //n-1�ˣ����һ��λ�ò���Ҫ�Ƚ� 
		int index=i;
		for(int j=i;j<size;j++){
			if(a[j]<a[index]){    //ȡÿһ��ѭ������Сֵ 
				index=j;
			}
		}
		swap(a,index,i);
	}
} 


int main(){
	int a[]={90,40,20,17,38,15};
	int size=6;
	SelectSort(a,size);
	print(a,size);
	
	return 0;
}
