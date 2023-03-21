#include<stdio.h>
using namespace std;

//从小到大排序 
//数组从1下标开始 
//数组传参本质上就是退化为指针传参，对真实数据进行修改 
void swap(int a[],int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

//打印
void print(int a[],int size){
	for(int i=1;i<=size;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
} 

//调整以K为根的子树 
void HeadAdjust(int a[],int k,int size){
	int temp=a[k];
	for(int i=2*k;i<=size;i*=2){
		if(i<size&&a[i]<a[i+1]) i++;//找到左右孩子中更大的
		if(temp>=a[i]){ //根节点大于孩子，不需要调整 
			break;
		}
		if(temp<a[i]){  //根节点小于孩子 
			a[k]=a[i];
			k=i;   //继续向下比较，将比temp大的孩子上移 
		} 
	} 
	a[k]=temp;
} 

//建立大跟堆
void BuildMaxHeap(int a[],int size){
	//从非叶子节点开始调整
	//非叶子节点下标<=size/2 
	for(int i=size/2;i>0;i--){
		HeadAdjust(a,i,size);
	}
} 

//堆排序
void HeapSort(int a[],int size){	
	BuildMaxHeap(a,size);   //将数组转换为大根堆 
	//每一趟都将根节点和堆的最后一个节点互换 
	for(int i=size;i>=1;i--){
		swap(a,1,i);
		HeadAdjust(a,1,i-1);
	}
} 

//堆的插入
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

//堆的删除
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
