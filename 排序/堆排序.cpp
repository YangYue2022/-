#include<stdio.h>
using namespace std;

//��С�������� 
//�����1�±꿪ʼ 
//���鴫�α����Ͼ����˻�Ϊָ�봫�Σ�����ʵ���ݽ����޸� 
void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

//��ӡ
void print(int a[],int size){
	for(int i=1;i<=size;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
} 

//������KΪ�������� 
void HeadAdjust(int a[],int k,int size){
	int temp=a[k];
	for(int i=2*k;i<=size;i*=2){
		if(i<size&&a[i]<a[i+1]) i++;//�ҵ����Һ����и����
		if(temp>=a[i]){ //���ڵ���ں��ӣ�����Ҫ���� 
			break;
		}
		if(temp<a[i]){  //���ڵ�С�ں��� 
			a[k]=a[i];
			k=i;   //�������±Ƚϣ�����temp��ĺ������� 
		} 
	} 
	a[k]=temp;
} 

//���������
void BuildMaxHeap(int a[],int size){
	//�ӷ�Ҷ�ӽڵ㿪ʼ����
	//��Ҷ�ӽڵ��±�<=size/2 
	for(int i=size/2;i>0;i--){
		HeadAdjust(a,i,size);
	}
} 

//������
void HeapSort(int a[],int size){	
	BuildMaxHeap(a,size);   //������ת��Ϊ����� 
	//ÿһ�˶������ڵ�Ͷѵ����һ���ڵ㻥�� 
	for(int i=size;i>=1;i--){
		swap(a,1,i);
		HeadAdjust(a,1,i-1);
	}
} 

//�ѵĲ���
void InsertHeap(int a[],int& size,int val){
	a[++size]=val;
	int i;
	for(i=size;i/2>=1;i=i/2){
		if(val>a[i/2]){
			a[i]=a[i/2];
		}
	}
	a[i]=val;
}

//�ѵ�ɾ��
void DeleteHeap(int a[],int& size,int i){
	swap(a,i,size--);
	HeadAdjust(a,i,size);
} 

int main(){
	int a[10]={0,40,20,17,38,15,90};
	int size=6;
//	HeapSort(a,size);
	BuildMaxHeap(a,size);
	print(a,size);
	InsertHeap(a,size,100);
	print(a,size);
	DeleteHeap(a,size,1);
	print(a,size);
	
	return 0;
}
