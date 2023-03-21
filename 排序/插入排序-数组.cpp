#include<stdio.h>
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

//插入排序 
void InsertSort(int a[],int size){
	
	if(size==1||a==NULL) return;
	
	for(int i=0;i<size;i++){
		for(int j=i;j>=1&&a[j]<a[j-1];j--){
			swap(a,j,j-1);
		}
	}
} 

//直接插入排序-王道实现方法 
void InsertSort1(int a[],int size){
	
	if(size==1||a==NULL) return;
	
	for(int i=1;i<size;i++){
		if(a[i]<a[i-1]){  //当a[i]小于它的前驱，才会向前排序 
			int temp=a[i];
			int j;
			for(j=i-1;j>=0&&temp<a[j];j--){
				a[j+1]=a[j];
			}
			a[j+1]=temp;
		}		
	}	
} 

//折半插入排序
void InsertSort2(int a[],int size){
	int left,right,mid;
	for(int i=1;i<size;i++){
		int temp=a[i];
		left=0;
		right=i-1;
		while(left<right){  //得到小于等于a[i]的最右侧下标 
			mid=(left+right+1)/2;  //向上取整
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

//希尔插入排序
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
