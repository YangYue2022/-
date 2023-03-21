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

//�������� 
void InsertSort(int a[],int size){
	
	if(size==1||a==NULL) return;
	
	for(int i=0;i<size;i++){
		for(int j=i;j>=1&&a[j]<a[j-1];j--){
			swap(a,j,j-1);
		}
	}
} 

//ֱ�Ӳ�������-����ʵ�ַ��� 
void InsertSort1(int a[],int size){
	
	if(size==1||a==NULL) return;
	
	for(int i=1;i<size;i++){
		if(a[i]<a[i-1]){  //��a[i]С������ǰ�����Ż���ǰ���� 
			int temp=a[i];
			int j;
			for(j=i-1;j>=0&&temp<a[j];j--){
				a[j+1]=a[j];
			}
			a[j+1]=temp;
		}		
	}	
} 

//�۰��������
void InsertSort2(int a[],int size){
	int left,right,mid;
	for(int i=1;i<size;i++){
		int temp=a[i];
		left=0;
		right=i-1;
		while(left<right){  //�õ�С�ڵ���a[i]�����Ҳ��±� 
			mid=(left+right+1)/2;  //����ȡ��
			if(a[mid]<=temp){
				left=mid;
			} else{
				right=mid-1;
			}
		}
		for(int j=i;j>right+1;j--){
			a[j]=a[j-1];
		} 
		a[right+1]=temp;
	}
} 

//ϣ����������
void InsertSort3(int a[],int size){
	
	if(size==1||a==NULL) return;
	
	for(int d=size/2;d>=1;d=d/2){
		for(int i=d;i<size;i++){
			int temp=a[i];
			int j=i-d;
			while(j>=0&&a[j]>temp){
				a[j+d]=a[j];
				j=j-d;
			}
			a[j+d]=temp;
		}
	}	
} 
int main(){
	int a[]={1,40,20,17,38,15};
	int size=6;
//	InsertSort(a,size);
//	InsertSort1(a,size);
//	InsertSort2(a,size);
	InsertSort3(a,size);
	print(a,size);
	
	return 0;
}
