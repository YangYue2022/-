#include <stdio.h>
#include <stdlib.h>
//二叉排序树
 
typedef struct BSTNode
{
	int data;
	BSTNode *lchild;  //左孩子
	BSTNode *rchild;  //右孩子
}BSTNode, *BSTree;
 
BSTNode* Search(BSTree t, int key){
	while(t!=NULL&&key!=t->data){ //如果查找到空，或查找到对应值，退出循环 
		if(key<t->data){
			t=t->lchild;
		}else{
			t=t->rchild;
		}
	}
	return t;
}
 
void InOderTraverse(BSTree bst)   //中序递归遍历二叉树
{
	if (NULL != bst)
	{
		InOderTraverse(bst->lchild);
		printf("%d ", bst->data);
		InOderTraverse(bst->rchild);
	}
}
 
//插入节点 
bool Insert(BSTree &t, int key)
{
	if (NULL == t)  //空树
	{
		t=(BSTree)malloc(sizeof(BSTNode));
		t->data=key;
		t->lchild=NULL;
		t->rchild=NULL;
		return true;
	}else if(t->data==key) {  //已经存在，插入失败 
		printf("\nThe node(%d) already exists.\n", key);
		return false;
	}else if(t->data<key){
		return Insert(t->rchild,key);
	}else{
		return Insert(t->lchild,key);
	}
}

//创建二叉排序树
void create(BSTree &t,int str[],int length){
	for(int i=0;i<length;i++){
		Insert(t,str[i]);
	} 
} 

/*
删除分三种情况：
(1)被删除的节点无孩子，说明该节点是叶子节点，直接删
(2)被删除的节点只有左孩子或者右孩子，直接删，并将其左孩子或者右孩子放在被删节点的位置
(3)被删除的节点既有右孩子又有右孩子
1.找到左子树的最右节点（没有右孩子），来替代删除节点，再由节点的左孩子替代它 ----此处用这种方法 
2.找到右子树的最左节点（没有左孩子），来替代删除节点，再由节点的右孩子替代它 
*/
bool Delete(BSTree& T, int key)
{
	if (NULL == T||Search(T,key)==NULL)
	{
		return false;  //空树或者差找不到直接报错
	}
	
	BSTNode* p=Search(T,key);
	BSTNode* q;
	BSTNode* s;

	if ( p->lchild==NULL &&  p->rchild !=NULL)  //无左孩子,有右孩子
	{
		q = p->rchild;
		p->data = q->data;    //因为两个节点之间本质的不同在于数据域的不同，而与放在哪个地址没有关系
		p->rchild = q->rchild;
		p->lchild = q->lchild;
		free(q);
	}
	else if (NULL == p->rchild && NULL != p->lchild)  //无右孩子,有左孩子
	{
		q = p->lchild;
		p->data = q->data;
		p->rchild = q->rchild;
		p->lchild = q->lchild;
		free(q);
	}
	else if (NULL != p->rchild && NULL != p->lchild) //既有左孩子，又有右孩子
	{
		q = p;
		s = p->lchild;   //找左孩子的最右孩子--s 
			while (s->rchild)
			{
				q = s;    //q存储s的父节点 
				s = s->rchild;
			}
			p->data = s->data;
 
			if (q != p)   
			{
				q->rchild = s->lchild;//用s的左孩子替代s 
			}
			else
			{
				q->lchild = s->lchild; //如果p的左孩子没有右孩子，也就是说p的左孩子就是左子树的最后结点 
			}
			free(s);
		}
		else  //叶子结点 
		{
			free(p); 
		}
		return true;
}
 
int main()
{
	BSTNode *root = NULL;
	int str[]={50,12,30,24,2,6};
	create(root,str,6);
	InOderTraverse(root);
	printf("\n");
	Delete(root,30);
	InOderTraverse(root);

	return 0;
}
