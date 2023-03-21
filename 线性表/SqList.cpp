#顺序表的静态存储 
#include <stdio.h>
#define MaxSize 10 // 定义最大长度 

typedef struct {
	int data[MaxSize];
	int length;
}SqList;
// 初始化
void InitList(SqList& L) {
	L.length = 0;
}
// 根据位序i插入e元素
bool ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i > L.length + 1) { // 是否合法 
		return false;
	}
	for (int j = L.length; j >= i; j--) {// 先向后移动
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;// 再i-1位置放置e
	L.length++; // 长度+1 
	return true;
}
// 根据位序i删除元素，返回删除的元素值e
bool ListDelete(SqList& L, int i, int& e) {
	if (i < 1 || i > L.length) {
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++) {// 删除的位置后的元素往前移动
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}
// 按位序i查找元素，返回值
int GetElem(SqList& L, int i) {
	if (i < 1 || i > L.length) {
		return 0;
	}
	return L.data[i - 1];
}
// 按值e查找元素，返回位序 
int LocateElem(SqList& L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (e == L.data[i]) {
			return i + 1;
		}
	}
	return 0;
}
// 遍历顺序表元素
void PrintList(SqList& L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.data[i]);
	}
	printf("\n");
}
int main() {
	int e;
	SqList L;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 3);
	ListInsert(L, 3, 4);
	ListInsert(L, 4, 5);
	printf("插入元素顺序表的元素为：\n");
	PrintList(L);
	printf("在位序2的位置插入元素：\n");
	ListInsert(L, 2, 2);// 插入2
	PrintList(L);
	if (ListDelete(L, 3, e)) {
		printf("删除位序3的元素%d成功：\n", e);
		PrintList(L);
	}
	printf("位序3的数是：%d\n", GetElem(L, 3));
	printf("数值是4的位序是：%d\n", LocateElem(L, 4));
}


