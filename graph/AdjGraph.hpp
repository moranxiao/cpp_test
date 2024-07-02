#include <stdio.h>
#include <stdlib.h>
#include "../queue/queue.hpp"
#define MAXV 100
#define MAX 100

typedef struct ANode
{
    int adjvex;
    struct ANode* nextarc;
    int weight;
}ArcNode;

typedef struct Vnode
{
//    InfoType data;
   ArcNode* firstarc;
}VNode;
typedef struct 
{
    VNode adjlist[MAXV];
    int n,e;
}AdjGraph;

void CreateAdj(AdjGraph*&G,int A[MAXV][MAXV],int n,int e)
{
    int i,j;ArcNode* p;
    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for(i = 0; i < n; i++)
        G->adjlist[i].firstarc=NULL;
    for(i = 0; i < n; i++)
    {
        for(j = n-1; j >= 0; j--)
        {
            if(A[i][j]!=0&&A[i][j]!=INT_MAX)
            {
                p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc=p;
            }
        }
    }
    G->n = n; G->e = e;
}

void DispAdj(AdjGraph* G)
{
    int i; ArcNode* p;
    for(i = 0; i < G->n;i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%3d;",i);
        while(p != NULL)
        {
            printf("%3d[%d]->",p->adjvex,p->weight);
            p = p->nextarc;
        }
        printf("^\n");
    }
}

void DestroyAdj(AdjGraph*&G)
{
    ArcNode* pre,*p;
    for(int i = 0; i < G->n;i++)
    {
        pre = G->adjlist[i].firstarc;
        if(pre!=NULL)
        {
            p = pre->nextarc;
            while(p!=NULL)
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
        }
    }
    free(G);
}

int visited[MAX] = {0};

void DFS(AdjGraph*G,int v)
{
    ArcNode*p;
    visited[v] = 1;
    printf("%d", v);
    p = G->adjlist[v].firstarc;
    while(p != NULL)
    {
        if(visited[p->adjvex] == 0)
            DFS(G,p->adjvex);
        p = p->nextarc;
    }
}

void BFS(AdjGraph* G,int v)
{
    int w,i; ArcNode*p;
    Queue* qu;
    qu = createQueue(MAXV);
    int visited[MAXV];
    for(i = 0; i < G->n; i++) visited[i] = 0;
    printf("%2d", v);
    visited[v] = 1;
    enqueue(qu,v);
    while(!isEmpty(qu))
    {
        dequeue(qu,&w);
        p = G->adjlist[w].firstarc;
        while(p != NULL)
        {
            if(visited[p->adjvex] == 0)
            {
                printf("%2d",p->adjvex);
                visited[p->adjvex] = 1;
                enqueue(qu,p->adjvex);
            }
            p=p->nextarc;
        }
    }
    printf("\n");
    
}