#include <stdio.h>
using namespace std;

int Binary_Search(int a[],int i){
	int low=0;
	int high=3;
	int mid;
	
	while(low<high){
		mid=(low+high)/2;
		if(a[mid]<i){
			low=mid+1;
		}else if(a[mid]>i){
			high=mid;
		}else{
			return mid;
		}
	}
	
	return -1;
}

int main(){
	int a[]={1,12,34,45};

	int i;
	printf("����Ҫ���ҵ�����");
	scanf("%d",&i); 
	//�۰����
	int res=Binary_Search(a,i) ;
	printf(res==-1?"û�ҵ�":"���Ϊ��%d",res);
}
