#include <stdio.h>
#include <stdlib.h>
//����������
 
typedef struct BSTNode
{
	int data;
	BSTNode *lchild;  //����
	BSTNode *rchild;  //�Һ���
}BSTNode, *BSTree;
 
BSTNode* Search(BSTree t, int key){
	while(t!=NULL&&key!=t->data){ //������ҵ��գ�����ҵ���Ӧֵ���˳�ѭ�� 
		if(key<t->data){
			t=t->lchild;
		}else{
			t=t->rchild;
		}
	}
	return t;
}
 
void InOderTraverse(BSTree bst)   //����ݹ����������
{
	if (NULL != bst)
	{
		InOderTraverse(bst->lchild);
		printf("%d ", bst->data);
		InOderTraverse(bst->rchild);
	}
}
 
//����ڵ� 
bool Insert(BSTree &t, int key)
{
	if (NULL == t)  //����
	{
		t=(BSTree)malloc(sizeof(BSTNode));
		t->data=key;
		t->lchild=NULL;
		t->rchild=NULL;
		return true;
	}else if(t->data==key) {  //�Ѿ����ڣ�����ʧ�� 
		printf("\nThe node(%d) already exists.\n", key);
		return false;
	}else if(t->data<key){
		return Insert(t->rchild,key);
	}else{
		return Insert(t->lchild,key);
	}
}

//��������������
void create(BSTree &t,int str[],int length){
	for(int i=0;i<length;i++){
		Insert(t,str[i]);
	} 
} 

/*
ɾ�������������
(1)��ɾ���Ľڵ��޺��ӣ�˵���ýڵ���Ҷ�ӽڵ㣬ֱ��ɾ
(2)��ɾ���Ľڵ�ֻ�����ӻ����Һ��ӣ�ֱ��ɾ�����������ӻ����Һ��ӷ��ڱ�ɾ�ڵ��λ��
(3)��ɾ���Ľڵ�����Һ��������Һ���
1.�ҵ������������ҽڵ㣨û���Һ��ӣ��������ɾ���ڵ㣬���ɽڵ����������� ----�˴������ַ��� 
2.�ҵ�������������ڵ㣨û�����ӣ��������ɾ���ڵ㣬���ɽڵ���Һ�������� 
*/
bool Delete(BSTree& T, int key)
{
	if (NULL == T||Search(T,key)==NULL)
	{
		return false;  //�������߲��Ҳ���ֱ�ӱ���
	}
	
	BSTNode* p=Search(T,key);
	BSTNode* q;
	BSTNode* s;

	if ( p->lchild==NULL &&  p->rchild !=NULL)  //������,���Һ���
	{
		q = p->rchild;
		p->data = q->data;    //��Ϊ�����ڵ�֮�䱾�ʵĲ�ͬ����������Ĳ�ͬ����������ĸ���ַû�й�ϵ
		p->rchild = q->rchild;
		p->lchild = q->lchild;
		free(q);
	}
	else if (NULL == p->rchild && NULL != p->lchild)  //���Һ���,������
	{
		q = p->lchild;
		p->data = q->data;
		p->rchild = q->rchild;
		p->lchild = q->lchild;
		free(q);
	}
	else if (NULL != p->rchild && NULL != p->lchild) //�������ӣ������Һ���
	{
		q = p;
		s = p->lchild;   //�����ӵ����Һ���--s 
			while (s->rchild)
			{
				q = s;    //q�洢s�ĸ��ڵ� 
				s = s->rchild;
			}
			p->data = s->data;
 
			if (q != p)   
			{
				q->rchild = s->lchild;//��s���������s 
			}
			else
			{
				q->lchild = s->lchild; //���p������û���Һ��ӣ�Ҳ����˵p�����Ӿ���������������� 
			}
			free(s);
		}
		else  //Ҷ�ӽ�� 
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
