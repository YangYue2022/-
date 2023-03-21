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

//简单选择排序
void SelectSort(int a[],int size){
	for(int i=0;i<size-1;i++){  //n-1趟，最后一个位置不需要比较 
		int index=i;
		for(int j=i;j<size;j++){
			if(a[j]<a[index]){    //取每一次循环的最小值 
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
