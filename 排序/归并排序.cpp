#include<stdio.h>
#include <stdlib.h>
using namespace std;

//从小到大排序 
//数组传参本质上就是退化为指针传参，对真实数据进行修改 
void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

//打印
void print(int a[],int size){
	for(int i=0;i<size;i++){
		printf("%d ",a[i]);
	}
} 

//b数组复制a数组的内容
int* b=(int*)malloc((6*sizeof(int))); 

void Merge(int a[],int low,int mid,int high){
	for(int i=low;i<=high;i++){
		b[i]=a[i];
	}
	int i=low;//左指针
	int j=mid+1; //右指针
	int k=low; //指向原数组的指针 
	while(i<=mid&&j<=high){
		if(b[i]<=b[j]){
			a[k++]=b[i++];
		}else{
			a[k++]=b[j++];
		}
	} 
	while(i<=mid) a[k++]=b[i++];
	while(j<=high) a[k++]=b[j++]; 
}

void MergeSort(int a[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}

int main(){
	int a[]={90,40,20,17,38,15};
	int size=6;
	MergeSort(a,0,5);
	print(a,size);
	return 0;
}
