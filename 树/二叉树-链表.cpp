#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
//�������� 
typedef struct BiTNode {
	int data; 		// ������ 
	struct BiTNode* lchild, * rchild;// ���Һ���ָ�� 
	struct BiTNode* parent;// ���׽�� 
}BiTNode, * BiTree;
// �������� 
bool InsertRootNode(BiTree& btree, int e) {
	btree=(BiTNode*)malloc(sizeof(BiTNode));
	btree->data=e;
	btree->lchild=NULL;
	btree->rchild=NULL;
	btree->parent=NULL;
	return true; 
}
// 1.��ǰp�������� 
BiTNode* GetLeftC(BiTNode* p) {
	if(p==NULL) return NULL;
	return p->lchild;
}
// 2.��ǰp�����Һ���  
BiTNode* GetRightC(BiTNode* p) {
	if(p==NULL) return NULL;
	return p->rchild;
}
// 3.��ǰp���ĸ���  
BiTNode* GetParent(BiTNode* p) {
	if(p==NULL) return NULL;
	return p->parent; 
}
// ��ǰ���c����һ������
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
	return root==NULL?true:false;
}
// ����������������� 
void InOrder(BiTree p) {// ������������ 
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%d  ", p->data);
		InOrder(p->rchild);
	}
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

	// ���Ի�ȡ���ҽ�� ����㷽��
	cur = GetLeftC(root->lchild->lchild);
	if (cur != NULL) {
		printf("���%d��������%d\n", root->lchild->lchild->data, cur->data);
	}
	cur = GetRightC(root->rchild->rchild);
	if (cur != NULL) {
		printf("���%d���ҽ����%d\n", root->rchild->rchild->data, cur->data);
	}
	cur = GetParent(root->lchild->rchild);
	if (cur != NULL) {
		printf("���%d�ĸ��׽����%d\n", root->lchild->rchild->data, cur->data);
	}
	printf("���������\n");
	InOrder(root);
	// ɾ���ڵ�
	printf("\nɾ�����%d�����������\n", root->lchild->data);
	DeleteTreeNode(root->lchild);
	InOrder(root);
	printf("\n");
}


