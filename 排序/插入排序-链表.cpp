//��ͷ���ĵ�����
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,* LinkList;

// ������Ľ���
LNode* List_TailInsert(LinkList& l) {// β�巨 
	l=(LNode*)malloc(sizeof(LNode));
	l->next=NULL;
	LNode* s;
	LNode* temp=l;
	int x;
	scanf("%d",&x);
	while(x!=0){
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=NULL;
		temp->next=s;
		temp=s;
		scanf("%d",&x);
	}
	temp->next=NULL;
	return l;
}

// ���
int Length(LNode* l) {
	int i=0;
	for(LNode* s=l;s->next!=NULL;s=s->next){
		i++;
	}
	return i;
}
// �������
void PrintLinkList(LinkList& l) {
	printf("��ʼ��ӡ");
	LNode* p = l;
	while (p->next != NULL) {
		p = p->next;
		printf("%d ", p->data);// �ź�����Ϊͷ�����û��ֵ�� 
	}
	printf("\n");
}

//��������
void InsertSort(LinkList& l){
	if(Length(l)==0||Length(l)==1) return;
	LNode* lastSorted=l->next;
	LNode* cur=l->next->next;
	while(cur){ 
		if(cur->data>=lastSorted->data){    //�����ǰ��ֵ����ǰһ��ֵ����˵���Ѿ��ź��� 
			lastSorted=cur;
			cur=cur->next;
		}else{  //��Ҫ��ͷ�ҵ�Ҫ�����λ�� 
			LNode* temp=l;
			while(temp->next->data<=cur->data){
				temp=temp->next;
			}
			
			LNode* s=cur; //��s�洢��ǰcur
			cur=cur->next;  //cur���� 
			lastSorted->next=cur;
			
			//�ڵ�sҪ����temp����
			s->next= temp->next;
			temp->next=s;
						
			
		}
	} 
	
} 

int main() {
	int e;
	// ʵ�ֲ���
	LNode* L;
	printf("����ֵ������������0����\n");
	List_TailInsert(L);// β��
	InsertSort(L);
	PrintLinkList(L);
	
}
 
