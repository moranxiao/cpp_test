
#pragma once
//图的基本运算算法
#include <stdio.h>
#include <malloc.h>
//图的两种存储结构
#define INF 32767				//定义∞
#define	MAXV 100				//最大顶点个数
typedef char InfoType;

//以下定义邻接矩阵类型
typedef struct
{
	int no;						//顶点编号
	InfoType info;				//顶点其他信息
} VertexType;					//顶点类型
typedef struct
{
	int edges[MAXV][MAXV];		//邻接矩阵数组
	int n, e;					//顶点数，边数
	VertexType vexs[MAXV];		//存放顶点信息
} MatGraph;						//完整的图邻接矩阵类型

//以下定义邻接表类型
typedef struct ANode
{
	int adjvex;					//该边的邻接点编号
	struct ANode* nextarc;		//指向下一条边的指针
	int weight;					//该边的相关信息，如权值（用整型表示）
} ArcNode;						//边节点类型
typedef struct Vnode
{
	InfoType info;				//顶点其他信息
	int count;					//存放顶点入度,仅仅用于拓扑排序
	ArcNode* firstarc;			//指向第一条边
} VNode;						//邻接表头节点类型
typedef struct
{
	VNode adjlist[MAXV];		//邻接表头节点数组
	int n, e;					//图中顶点数n和边数e
} AdjGraph;						//完整的图邻接表类型

//------------------------------------------------------------
//----邻接矩阵的基本运算算法----------------------------------
//------------------------------------------------------------
void CreateMat(MatGraph& g, int A[MAXV][MAXV], int n, int e) //创建图的邻接矩阵
{
	int i, j;
	g.n = n; g.e = e;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
}
void DispMat(MatGraph g)	//输出邻接矩阵g
{
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j] != INF)
				printf("%4d", g.edges[i][j]);
			else
				printf("%4s", "∞");
		printf("\n");
	}
}
//------------------------------------------------------------

//------------------------------------------------------------
//----邻接表的基本运算算法------------------------------------
//------------------------------------------------------------
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) //创建图的邻接表
{
	int i, j;
	ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)						//给邻接表中所有头节点的指针域置初值
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++)						//检查邻接矩阵中每个元素
		for (j = n - 1; j >= 0; j--)
			if (A[i][j] != 0 && A[i][j] != INF)	//存在一条边
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));	//创建一个节点p
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;	//采用头插法插入节点p
				G->adjlist[i].firstarc = p;
			}
	G->n = n; G->e = e;
}
void DispAdj(AdjGraph* G)	//输出邻接表G
{
	ArcNode* p;
	for (int i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%3d: ", i);
		while (p != NULL)
		{
			printf("%3d[%d]→", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("  ∧\n");
	}
}
void DestroyAdj(AdjGraph*& G)	//销毁图的邻接表
{
	ArcNode* pre, * p;
	for (int i = 0; i < G->n; i++)		//扫描所有的单链表
	{
		pre = G->adjlist[i].firstarc;	//p指向第i个单链表的首节点
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)			//释放第i个单链表的所有边节点
			{
				free(pre);
				pre = p; p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);						//释放头节点数组
}

#define MaxSize 100
int visited[MAXV];						//全局数组
void DFS(AdjGraph* G, int v)				//递归深度优先遍历算法
{
	ArcNode* p;
	visited[v] = 1;                   	//置已访问标记
	printf("%3d", v); 					//输出被访问顶点的编号	      		 
	for (p = G->adjlist[v].firstarc; p != NULL; p = p->nextarc)
		if (!visited[p->adjvex])		//若p->adjvex顶点未访问,递归访问它
			DFS(G, p->adjvex);
}

//---------------------------------------------------------
//--广度优先遍历中使用队列的基本运算算法-------------------
//---------------------------------------------------------
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;		//队首和队尾指针
} SqQueue;
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
void DestroyQueue(SqQueue*& q)
{
	free(q);
}
bool QueueEmpty(SqQueue* q)
{
	return(q->front == q->rear);
}
bool enQueue(SqQueue*& q, ElemType e)
{
	if ((q->rear + 1) % MaxSize == q->front)	//队满上溢出
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)				//队空下溢出
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}
//---------------------------------------------------------

void BFS(AdjGraph* G, int v)
{
	int w;
	ArcNode* p;
	SqQueue* qu;							//定义环形队列指针
	InitQueue(qu);							//初始化队列
	int visited[MAXV] = { 0 };            			//定义顶点访问标志数组
	//for (i=0;i<G->n;i++) visited[i]=0;		//访问标志数组初始化
	printf("%3d", v); 						//输出被访问顶点的编号
	visited[v] = 1;              				//置已访问标记
	enQueue(qu, v);
	while (!QueueEmpty(qu))       			//队不空循环
	{
		deQueue(qu, w);						//出队一个顶点w 
		for (p = G->adjlist[w].firstarc; p != NULL; p = p->nextarc) //查找w的所有邻接点 
			if (!visited[p->adjvex]) 		//若当前邻接点未被访问
			{
				printf("%3d", p->adjvex);  	//访问该邻接点
				visited[p->adjvex] = 1;		//置已访问标记
				enQueue(qu, p->adjvex);		//该顶点进队
			}
	}
	printf("\n");
}


int main()
{
	AdjGraph* G;
	int A[MAXV][MAXV] = {
	{0,5,INF,7,INF,INF},
	{INF,0,4,INF,INF,INF},
	{8,INF,0,INF,INF,9},
	{INF,INF,5,0,INF,6},
	{INF,INF,INF,5,0,INF},
	{3,INF,INF,INF,1,0} };
	int n = 6, e = 10;
	CreateAdj(G, A, n, e); //创建图
	printf("图G的邻接表:\n");
	DispAdj(G);
	printf("从顶点0开始的DFS(递归算法):\n");
	DFS(G, 0);
	printf("\n从顶点0开始的BFS:\n");
	BFS(G, 0);
	DestroyAdj(G);
	return 0;
}

