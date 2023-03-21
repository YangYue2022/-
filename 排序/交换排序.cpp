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

//ð������ 
void BubbleSort(int a[],int size){
	for(int i=0;i<size;i++){  //һ��size��,ÿһ��ȷ��һ����Сֵ 
		for(int j=size-2;j>=i;j--){
			if(a[j]>a[j+1]){  //���ʱ����������֤�㷨�ȶ� 
				swap(a,j,j+1);    //��С��ֵ���ϸ� 
			}
		}
	}
}


int partition(int a[],int low,int high){
	int pivot=a[low];
	while(low<high){
		while(low<high&&a[high]>=pivot) high--;
		a[low]=a[high];
		while(low<high&&a[low]<=pivot) low++;
		a[high]=a[low]; 
	}
	a[low]=pivot;
	return low;
}

//��������
void QuickSort(int a[], int low,int high){
	if(low<high){
		int pivotpos=partition(a,low,high);
		QuickSort(a,low,pivotpos-1);
		QuickSort(a,pivotpos+1,high);
	}
}

 
int main(){
	int a[]={90,40,20,17,38,15};
	int size=6;
//	BubbleSort(a,size);
	QuickSort(a,0,5);
	print(a,size);
	
	return 0;
}
