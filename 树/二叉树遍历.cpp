#include <stdio.h> 
#include <stdlib.h>
#include <cmath> // Ϊ��ʵ��log���㣬����cmath��
#include <queue> // �������У�ʵ�ֲ�α���
#include <stack> // ����ջ��ʵ�ֵ��Ʊ���
using namespace std;

typedef struct BiTNode {
	int data; 		// ������ 
	struct BiTNode* lchild, * rchild;// ���Һ���ָ�� 
	struct BiTNode* parent;// ���׽�� 
}BiTNode, * BiTree;

// �������� 
bool InsertRootNode(BiTree& btree, int e) {
	btree = (BiTree)malloc(sizeof(BiTNode));
	btree->data = e;

	btree->lchild = NULL;
	btree->rchild = NULL;
	btree->parent = NULL;
	return true;
}

// 1.��ǰp�������� 
BiTNode* GetLeftC(BiTree& p) {
	if (p == NULL ) {
		return NULL;
	}
	return p->lchild;
}
// 2.��ǰ�����Һ���  
BiTNode* GetRightC(BiTree& p) {
	if (p == NULL) {
		return NULL;
	}
	return p->rchild;
}
// 3.��ǰp���ĸ���  
BiTNode* GetParent(BiTree& p) {
	if (p == NULL ) {
		return NULL;
	}
	return p->parent;
}

// ��ǰc������һ������
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
// ��ǰc������һ���ҽ��
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
// ɾ��c�ڵ� : Ҫɾ��c�������ҽ�㣬�����ͷſռ�
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
// �ж϶������Ƿ�Ϊ��
bool Empty(BiTree& root) {
	if (root == NULL) {
		return true;
	}
	return false;
}
// ��С���ص�------------------------------------------------
// ǰ����� 
void PreOrder(BiTree p) {// ������������ 
	if (p != NULL) {
		printf("%d  ", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}
// ������� 
void InOrder(BiTree p) {// ������������ 
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%d  ", p->data);
		InOrder(p->rchild);
	}
}
// ������� 
void PostOrder(BiTree p) {// ������������ 
	if (p != NULL) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d  ", p->data);
	}
}
// ��α��� 
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
// �ѵ�------------------------------------------------
// �ǵݹ����
void PreOrderDiTui(BiTree& root) {// ǰ��
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
void InOrderDiTui(BiTree& root) {// ���� 
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
void PostOrderDiTui(BiTree& root) {// ���� 
	stack<BiTNode*> bistack;
	BiTNode* p = root;
	BiTNode* lastp = NULL;// ��һ�����ʵĽ�� ,�ؼ��㣡�������ж��Ƿ����������� 
	while(p!=NULL||!bistack.empty()){
		if(p!=NULL){
			bistack.push(p);
			p=p->lchild;
		}else{
			
			p=bistack.top();
			
			//��ʱ�����ֿ���
			//1.�������������ٴλص����ڵ�(��������������������������Ϊ�վͲ�������) 
			//2.��������������������Ϊ�գ�ֱ��pop�����ʣ�
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
	// �ֶ���������� 
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
	
	printf("ǰ�����:\n");
	PreOrder(root);
	printf("\n�������:\n");
	InOrder(root);
	printf("\n�������:\n");
	PostOrder(root);
	printf("\n��α���:\n");
	CenCi(root);

	// ɾ���ڵ�
	printf("\nɾ�����%d����Ʊ�����������\n", root->lchild->data);
	DeleteTreeNode(root->lchild);
	printf("����ǰ�����:\n");
	PreOrderDiTui(root);
	printf("�����������:\n");
	InOrderDiTui(root);
	printf("���ƺ������:\n");
	PostOrderDiTui(root);
	printf("��α���:\n");
	CenCi(root);
}


