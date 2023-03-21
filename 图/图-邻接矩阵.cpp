#include <stdio.h>
#include <stdlib.h>
#include <queue> // 借助队列，实现广度优先遍历
using namespace std;

#define MAXVEX  100                      //最大顶点数
#define INFINITY    65535               //用65535来代表无穷大
 
 
bool visited[MAXVEX]={false};
 
 
typedef struct
{
    int vexs[MAXVEX];            //顶点表
    int  arc[MAXVEX][MAXVEX];         //邻接矩阵，可看作边
    int  numVertexes, numEdges;      //图中当前的顶点数和边数
}Graph;

int findIndex(Graph g,int i){
	//找到i对应的下标
	int index=-1;
	for(int j=0;j<g.numVertexes;j++){
		if(g.vexs[j]==i){
			index=j;
			break;
		}
	} 
	if(index==-1){
		printf("图中不存在对应节点");
	}
	return index;
} 

void CreateGraph(Graph &G) {
	/*初始化图的基本信息*/
	//输入图中顶点 
	printf("请输入图中顶点数量：");
	scanf("%d",&G.numVertexes);
	for(int i=0;i<G.numVertexes;i++){
		printf("请输入第%d个顶点:",i+1);
		scanf("%d",&G.vexs[i]);
	}
	//输入图中的边 
	printf("请输入图中边的数量：");
	scanf("%d",&G.numEdges);
	//初始化邻接矩阵
	for(int i=0;i<G.numVertexes;i++){
		for(int j=0;j<G.numVertexes;j++){
			G.arc[i][j] = 0;  //初始化时顶点间都不存在边 
		}
	} 
	//构造邻接矩阵
	for(int k=0;k<G.numEdges;k++) {
		int v1,v2;
		printf("请输入第%d条边（如：AB):",k+1);
		scanf("%d %d",&v1,&v2);
		int i=findIndex(G,v1);
		int j=findIndex(G,v2); 
		G.arc[i][j] = 1;  //存在边就设置为1 
		G.arc[j][i] = 1;  //由于是无向图所以相反反向也存在边 
	}
	printf("图创建成功！\n");	 
}

 
//找到第一个与下标index的点相邻的点 ,-1表示找不到 
int firstNeighbor(Graph g,int index){
	for(int j=0;j<g.numVertexes;j++){
		if(g.arc[index][j]==1){
			return j;
		}
	}
	return -1;
}

//找到下一个相邻的点
int nextNeighbor(Graph g,int index,int now){
	for(int j=now+1;j<g.numVertexes;j++){
		if(g.arc[index][j]==1){
			return j;
		}
	}
	return -1;
} 

void bfs (Graph g,int i)   //广度优先遍历 
{
	
	queue<int> que;
	printf("%d ",g.vexs[i]);
	visited[i]=true;
	que.push(i);
	while(!que.empty()){
		int index=que.front();
		que.pop();
		for(int j=firstNeighbor(g,index);j>=0;j=nextNeighbor(g,index,j)){ //访问所有与i相连的节点 
			if(!visited[j]){  //只会访问未被访问的节点 
				printf("%d ",g.vexs[j]);
				visited[j]=true;
				que.push(j);
			}
		}
	}
	
}

void BFSTraverse(Graph g,int i){
	for(int j=0;j<g.numVertexes;j++){  //将所有节点标志为未访问 
		visited[j]=false;
	}
	int index=findIndex(g,i);
	if(index==-1) return;
	
	bfs(g,index);//如果直接从0节点开始遍历，可以省去这一行代码 
	
	//如果是非连通图，则经过bfs还会有子图未访问到，遍历visited找还没有访问的点 
	for(int j=0;j<g.numVertexes;j++){
		if(!visited[j]){
			bfs(g,j);
		}
	} 
}

void dfs(Graph g,int i){
	printf("%d ",g.vexs[i]);
	visited[i]=true;
	for(int j=firstNeighbor(g,i);j>=0;j=nextNeighbor(g,i,j)){ //访问所有与i相连的节点 
			if(!visited[j]){  //只会访问未被访问的节点 
				dfs(g,j);
			}
		}
}

void DFSTraverse(Graph g){
	for(int j=0;j<g.numVertexes;j++){  //将所有节点标志为未访问 
		visited[j]=false;
	}
	
	//如果是非连通图，则经过bfs还会有子图未访问到，遍历visited找还没有访问的点 
	//从0开始遍历 
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
    printf("\n输入i:");
    scanf("%d",&i);

    printf("广度优先搜索遍历：");
    BFSTraverse(g,i);
    
    printf("\n深度优先搜索遍历：");
    DFSTraverse(g);
    
    return 0;
}
