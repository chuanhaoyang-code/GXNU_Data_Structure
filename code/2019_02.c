#include<stdio.h>
#include<stdlib.h>

#define N 5

int GM[N][N];

typedef struct GNode{
	int v; // 顶点编号 
	int w; // 权值 
	struct GNode *next;
}*GNode;

GNode GT[N];

int main(){
	// 创建邻接表 
	int i;
	for(i=0;i<=N;i++){
		GT[i]=(GNode)malloc(sizeof(GNode));
		GT[i]->v=-1,GT[i]->w=-1,GT[i]->next=NULL;
	}
	
	
	while(1)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		if(x==-1||y==-1||w==-1)break;
		GNode p = GT[x-1];
		while(p->next)p=p->next;
		GNode q = (GNode)malloc(sizeof(GNode));
		q->v=y,q->w=w,q->next=NULL;
		p->next=q;	

	}
	// 打印邻接表

	for(i=0;i<N;i++){
		GNode p = GT[i]->next;
		printf("\n| 结点%d | -> ",i+1);
		while(p){
			printf("| %d | %d | -> ",p->v,p->w);
			p=p->next;
		}
		printf("NULL");
	} 
	
	
	return 0;
} 







/*
起点 终点 权重 
1 2 9
1 3 2
1 5 6
2 1 9
2 3 3
3 1 2 
3 2 3
3 4 5 
4 3 5
4 5 1
5 1 6
5 4 1 
-1 -1 -1
*/ 







