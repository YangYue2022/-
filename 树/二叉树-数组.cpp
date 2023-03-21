#include <stdio.h> 
#include <cmath>

#define TreeSize 99 
#define MaxSize 100
/* 
以完全二叉树形式存储结点
i的左孩子：2i
i的右孩子：2i+1
i的父节点：i/2 向下取整
i所在的层次（深度）：log2 (n) + 1
*/
struct TreeNode {
	int value; 		// 节点中的数据元素 
	bool isEmpty; 	// 结点是否为空 
};
// 初始化
void InitTreeNode(TreeNode(&t)[MaxSize]) {
	for(int i=0;i<=MaxSize;i++){
		t[i].isEmpty=true;
	} 
}
// 位序i结点的左孩子 
TreeNode GetLeftC(TreeNode(&t)[MaxSize], int i) {
	int j=2*i;
	if(j<1||j>MaxSize||t[j].isEmpty) return t[0];
	return t[j];
}
// 位序i结点的右孩子 
TreeNode GetRightC(TreeNode(&t)[MaxSize], int i) {
	int j=2*i+1;
	if(j<1||j>MaxSize||t[j].isEmpty) return t[0];
	return t[j];
}
// 位序i结点的父结点 
TreeNode GetParentC(TreeNode(&t)[MaxSize], int i) {
	int j=i/2;
	if(j<1||j>MaxSize||t[j].isEmpty) return t[0];
	return t[j];
}
// 位序i结点层次（深度） 
int GetDepth(TreeNode(&t)[MaxSize], int i) {
	if(i<1||i>MaxSize) return 0;
	int j=log(i)/log(2)+1;
	return j;
}
// 在位序i的位置插入一个结点
bool InsertTreeNode(TreeNode(&t)[MaxSize], int i, int e) {
	if(i<1||i>MaxSize){
		return false;
	}
	TreeNode s;
	s.isEmpty=false;
	s.value=e;
	t[i]=s;
	return true;
}
// 删除在位序i的位置上的结点 - 要注意把他的左右孩子也删除
bool DeleteTreeNode(TreeNode(&t)[MaxSize], int i, int& e) {
	if(i<1||i>MaxSize) return false;
	
	DeleteTreeNode(t,2*i,e);
	DeleteTreeNode(t,2*i+1,e);
	
	e=t[i].value;
	t[i].isEmpty=true;
	return true;
}
// 顺序遍历 
void PrintTreeNodeOrder(TreeNode(&t)[MaxSize]) {
	for(int i=1;i<MaxSize;i++){
		if(!t[i].isEmpty){
			printf("%d\t",t[i].value);
		}
	}
	printf("\n");
}
// 遍历各个结点详细信息
void PrintTreeNodeAll(TreeNode(&t)[MaxSize], int maxn) {
	TreeNode tn1, tn2, tn3;
	int depth;
	for (int i = 1; i < maxn; i++) {
		if (t[i].isEmpty) {
			printf("%d结点为空\n", i);
			continue;
		}
		tn1 = GetLeftC(t, i);	// 左结点
		tn2 = GetRightC(t, i);  // 有结点
		tn3 = GetParentC(t, i); // 父亲结点
		if (!tn3.isEmpty) {
			printf("%d结点的父结点是：%d\t", i, tn3.value);
		}
		else {
			printf("%d结点没有父结点 \t", i);
		}
		if (!tn1.isEmpty) {
			printf("%d结点的左结点是：%d\t", i, tn1.value);
		}
		else {
			printf("%d结点没有左结点 \t", i);
		}
		if (!tn2.isEmpty) {
			printf("%d结点的右结点是：%d\t", i, tn2.value);
		}
		else {
			printf("%d结点没有右结点 \t", i);
		}
		depth = GetDepth(t, i);
		printf("%d结点的深度是%d\n", i, depth);
	}
}
int main() {
	TreeNode t[MaxSize];
	InitTreeNode(t);
	// 插入节点
	int maxn = 16;
	for (int i = 1; i < maxn; i++) {
		InsertTreeNode(t, i, i);
	}
	printf("依次输出各个结点:\n");
	PrintTreeNodeOrder(t);
	printf("\n");
	printf("依次输出每个结点的详细信息：左右孩子、父亲、深度:\n");
	PrintTreeNodeAll(t, maxn);
	printf("\n");
	// 删除节点
	int e;
	DeleteTreeNode(t, 2, e);
	printf("删除结点2后，依次输出各个结点:\n");
	PrintTreeNodeOrder(t);
	printf("\n");
	printf("删除结点2后，各个结点详细信息:\n");
	PrintTreeNodeAll(t, maxn);
}


