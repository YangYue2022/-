#include <stdio.h> 
#include <stdlib.h>
#include <cmath> // 为了实现log运算，导入cmath库
#include <queue> // 借助队列，实现层次遍历
#include <stack> // 借助栈，实现递推遍历
using namespace std;

typedef struct BiTNode {
	int data; 		// 数据域 
	struct BiTNode* lchild, * rchild;// 左右孩子指针 
	struct BiTNode* parent;// 父亲结点 
}BiTNode, * BiTree;

// 插入根结点 
bool InsertRootNode(BiTree& btree, int e) {
	btree = (BiTree)malloc(sizeof(BiTNode));
	btree->data = e;

	btree->lchild = NULL;
	btree->rchild = NULL;
	btree->parent = NULL;
	return true;
}

// 1.当前p结点的左孩子 
BiTNode* GetLeftC(BiTree& p) {
	if (p == NULL ) {
		return NULL;
	}
	return p->lchild;
}
// 2.当前结点的右孩子  
BiTNode* GetRightC(BiTree& p) {
	if (p == NULL) {
		return NULL;
	}
	return p->rchild;
}
// 3.当前p结点的父亲  
BiTNode* GetParent(BiTree& p) {
	if (p == NULL ) {
		return NULL;
	}
	return p->parent;
}

// 当前c结点插入一个左结点
bool InsertTreeLeftNode(BiTree& c, int e) {
	if(c==NULL) return false;
	BiTNode* s=(BiTree)malloc(sizeof(BiTree));
	s->data=e;
	s->parent=c;
	s->lchild=NULL;
	s->rchild=NULL;
	c->lchild=s;
	return true;
}
// 当前c结点插入一个右结点
bool InsertTreeRightNode(BiTree& c, int e) {
	if(c==NULL) return false;
	BiTNode* s=(BiTree)malloc(sizeof(BiTree));
	s->data=e;
	s->parent=c;
	s->lchild=NULL;
	s->rchild=NULL;
	c->rchild=s;
	return true;
}
// 删除c节点 : 要删除c结点的左右结点，并且释放空间
bool DeleteTreeNode(BiTree& c) {
	if(c==NULL) return false;
	
	if(c->lchild!=NULL){
		DeleteTreeNode(c->lchild);
	}
	if(c->rchild!=NULL){
		DeleteTreeNode(c->rchild);
	} 
	
	if(c->parent!=NULL){
		BiTNode* s=c->parent;
		if(c==s->lchild){
			s->lchild=NULL;
		}else{
			s->rchild=NULL;
		}
	}

	free(c);
	return true;
}
// 判断二叉树是否为空
bool Empty(BiTree& root) {
	if (root == NULL) {
		return true;
	}
	return false;
}
// 本小节重点------------------------------------------------
// 前序遍历 
void PreOrder(BiTree p) {// 不能引用类型 
	if (p != NULL) {
		printf("%d  ", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}
// 中序遍历 
void InOrder(BiTree p) {// 不能引用类型 
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%d  ", p->data);
		InOrder(p->rchild);
	}
}
// 后序遍历 
void PostOrder(BiTree p) {// 不能引用类型 
	if (p != NULL) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d  ", p->data);
	}
}
// 层次遍历 
void CenCi(BiTree& root) { 
	queue<BiTNode*> que;
	que.push(root);
	BiTNode* p;
	while(!que.empty()){
		p=que.front();
		que.pop();
		printf("%d ",p->data);
		if(p->lchild!=NULL){
			que.push(p->lchild);
		}
		if(p->rchild!=NULL){
			que.push(p->rchild);
		}
	} 
}
// 难点------------------------------------------------
// 非递归遍历
void PreOrderDiTui(BiTree& root) {// 前序
	stack<BiTNode*> bistack;
	BiTNode* p=root;
	while(p!=NULL||!bistack.empty()){
		if(p!=NULL){
			bistack.push(p);
			printf("%d ",p->data);
			p=p->lchild;
		}else{
			p=bistack.top();
			bistack.pop();
			p=p->rchild;
		}
	}
	printf("\n");
}
void InOrderDiTui(BiTree& root) {// 中序 
	stack<BiTNode*> bistack;
	BiTNode* p = root;
	while (p != NULL || !bistack.empty()) {
		if (p != NULL) {
			bistack.push(p);
			p = p->lchild;
		}
		else {
			p = bistack.top();
			bistack.pop();
			printf("%d  ", p->data);
			p = p->rchild;
		}
	}
	printf("\n");
}
void PostOrderDiTui(BiTree& root) {// 后序 
	stack<BiTNode*> bistack;
	BiTNode* p = root;
	BiTNode* lastp = NULL;// 上一个访问的结点 ,关键点！，用来判断是否右子树返回 
	while(p!=NULL||!bistack.empty()){
		if(p!=NULL){
			bistack.push(p);
			p=p->lchild;
		}else{
			
			p=bistack.top();
			
			//此时有两种可能
			//1.访问完左子树再次回到父节点(需继续访问右子树，如果右子树为空就不访问了) 
			//2.访问完右子树或右子树为空（直接pop并访问）
			if(p->rchild==NULL||lastp==p->rchild){
				bistack.pop();
				printf("%d ",p->data);
				lastp=p;
				p=NULL;
			}else{
				p=p->rchild;
			}
		}
	}
	printf("\n");
}
int main() {
	// 手动构造二叉树 
	BiTree root = NULL;
	InsertRootNode(root, 1);
	BiTree cur = root;// cur = 1
	InsertTreeLeftNode(cur, 2);
	InsertTreeRightNode(cur, 3);

	cur = root->lchild;// cur = 2
	InsertTreeLeftNode(cur, 4);
	InsertTreeRightNode(cur, 5);

	cur = root->rchild;// cur = 3
	InsertTreeLeftNode(cur, 6);
	InsertTreeRightNode(cur, 7);

	cur = root->lchild->lchild;// cur = 4
	InsertTreeLeftNode(cur, 8);
	InsertTreeRightNode(cur, 9);

	cur = root->lchild->rchild;// cur = 5
	InsertTreeLeftNode(cur, 10);
	InsertTreeRightNode(cur, 11);

	cur = root->rchild->lchild;// cur = 6
	InsertTreeLeftNode(cur, 12);
	InsertTreeRightNode(cur, 13);

	cur = root->rchild->rchild;// cur = 7
	InsertTreeLeftNode(cur, 14);
	InsertTreeRightNode(cur, 15);
	
	printf("前序遍历:\n");
	PreOrder(root);
	printf("\n中序遍历:\n");
	InOrder(root);
	printf("\n后序遍历:\n");
	PostOrder(root);
	printf("\n层次遍历:\n");
	CenCi(root);

	// 删除节点
	printf("\n删除结点%d后递推遍历二叉树：\n", root->lchild->data);
	DeleteTreeNode(root->lchild);
	printf("递推前序遍历:\n");
	PreOrderDiTui(root);
	printf("递推中序遍历:\n");
	InOrderDiTui(root);
	printf("递推后序遍历:\n");
	PostOrderDiTui(root);
	printf("层次遍历:\n");
	CenCi(root);
}


