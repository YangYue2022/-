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

//冒泡排序 
void BubbleSort(int a[],int size){
	for(int i=0;i<size;i++){  //一共size趟,每一趟确定一个最小值 
		for(int j=size-2;j>=i;j--){
			if(a[j]>a[j+1]){  //相等时不交换，保证算法稳定 
				swap(a,j,j+1);    //最小的值向上浮 
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

//快速排序
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
