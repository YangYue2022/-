#include <stdio.h>
#include <stdlib.h>
#include <queue> // �������У�ʵ�ֹ�����ȱ���
using namespace std;

#define MAXVEX  100                      //��󶥵���
#define INFINITY    65535               //��65535�����������
 
 
bool visited[MAXVEX]={false};
 
 
typedef struct
{
    int vexs[MAXVEX];            //�����
    int  arc[MAXVEX][MAXVEX];         //�ڽӾ��󣬿ɿ�����
    int  numVertexes, numEdges;      //ͼ�е�ǰ�Ķ������ͱ���
}Graph;

int findIndex(Graph g,int i){
	//�ҵ�i��Ӧ���±�
	int index=-1;
	for(int j=0;j<g.numVertexes;j++){
		if(g.vexs[j]==i){
			index=j;
			break;
		}
	} 
	if(index==-1){
		printf("ͼ�в����ڶ�Ӧ�ڵ�");
	}
	return index;
} 

void CreateGraph(Graph &G) {
	/*��ʼ��ͼ�Ļ�����Ϣ*/
	//����ͼ�ж��� 
	printf("������ͼ�ж���������");
	scanf("%d",&G.numVertexes);
	for(int i=0;i<G.numVertexes;i++){
		printf("�������%d������:",i+1);
		scanf("%d",&G.vexs[i]);
	}
	//����ͼ�еı� 
	printf("������ͼ�бߵ�������");
	scanf("%d",&G.numEdges);
	//��ʼ���ڽӾ���
	for(int i=0;i<G.numVertexes;i++){
		for(int j=0;j<G.numVertexes;j++){
			G.arc[i][j] = 0;  //��ʼ��ʱ����䶼�����ڱ� 
		}
	} 
	//�����ڽӾ���
	for(int k=0;k<G.numEdges;k++) {
		int v1,v2;
		printf("�������%d���ߣ��磺AB):",k+1);
		scanf("%d %d",&v1,&v2);
		int i=findIndex(G,v1);
		int j=findIndex(G,v2); 
		G.arc[i][j] = 1;  //���ڱ߾�����Ϊ1 
		G.arc[j][i] = 1;  //����������ͼ�����෴����Ҳ���ڱ� 
	}
	printf("ͼ�����ɹ���\n");	 
}

 
//�ҵ���һ�����±�index�ĵ����ڵĵ� ,-1��ʾ�Ҳ��� 
int firstNeighbor(Graph g,int index){
	for(int j=0;j<g.numVertexes;j++){
		if(g.arc[index][j]==1){
			return j;
		}
	}
	return -1;
}

//�ҵ���һ�����ڵĵ�
int nextNeighbor(Graph g,int index,int now){
	for(int j=now+1;j<g.numVertexes;j++){
		if(g.arc[index][j]==1){
			return j;
		}
	}
	return -1;
} 

void bfs (Graph g,int i)   //������ȱ��� 
{
	
	queue<int> que;
	printf("%d ",g.vexs[i]);
	visited[i]=true;
	que.push(i);
	while(!que.empty()){
		int index=que.front();
		que.pop();
		for(int j=firstNeighbor(g,index);j>=0;j=nextNeighbor(g,index,j)){ //����������i�����Ľڵ� 
			if(!visited[j]){  //ֻ�����δ�����ʵĽڵ� 
				printf("%d ",g.vexs[j]);
				visited[j]=true;
				que.push(j);
			}
		}
	}
	
}

void BFSTraverse(Graph g,int i){
	for(int j=0;j<g.numVertexes;j++){  //�����нڵ��־Ϊδ���� 
		visited[j]=false;
	}
	int index=findIndex(g,i);
	if(index==-1) return;
	
	bfs(g,index);//���ֱ�Ӵ�0�ڵ㿪ʼ����������ʡȥ��һ�д��� 
	
	//����Ƿ���ͨͼ���򾭹�bfs��������ͼδ���ʵ�������visited�һ�û�з��ʵĵ� 
	for(int j=0;j<g.numVertexes;j++){
		if(!visited[j]){
			bfs(g,j);
		}
	} 
}

void dfs(Graph g,int i){
	printf("%d ",g.vexs[i]);
	visited[i]=true;
	for(int j=firstNeighbor(g,i);j>=0;j=nextNeighbor(g,i,j)){ //����������i�����Ľڵ� 
			if(!visited[j]){  //ֻ�����δ�����ʵĽڵ� 
				dfs(g,j);
			}
		}
}

void DFSTraverse(Graph g){
	for(int j=0;j<g.numVertexes;j++){  //�����нڵ��־Ϊδ���� 
		visited[j]=false;
	}
	
	//����Ƿ���ͨͼ���򾭹�bfs��������ͼδ���ʵ�������visited�һ�û�з��ʵĵ� 
	//��0��ʼ���� 
	for(int j=0;j<g.numVertexes;j++){
		if(!visited[j]){
			dfs(g,j);
		}
	} 
}

 
 
int main()
{
    Graph g;
    CreateGraph(g);
    
    int i;
    printf("\n����i:");
    scanf("%d",&i);

    printf("�����������������");
    BFSTraverse(g,i);
    
    printf("\n�����������������");
    DFSTraverse(g);
    
    return 0;
}
