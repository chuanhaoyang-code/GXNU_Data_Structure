#include<stdio.h>
#include<stdlib.h>

#define N 6
#define INF 65535

int GM[N][N]; // 邻接矩阵 

typedef struct GNode{
	int v; // 顶点
	int w; // 权重 
	struct GNode *next; 
}*GNode;

// 注意: 现在只是定义而已,没有分配空间 
GNode GT[N]; // 邻接表 




int main(){
	int i,j;
	// 初始化邻接矩阵 
	for(i=1;i<N;i++){
		for(j=1;j<N;j++){
			if(i==j)GM[i][j]=0;
			else GM[i][j]=INF;
		}
	}
	
	// 初始化邻接表
	// 就是给每个数组的第一个结点malloc一个空间,作为头结点 
	for(i=1;i<N;i++){
		GT[i]=(GNode)malloc(sizeof(GNode));
		GT[i]->v=-1,GT[i]->w=-1,GT[i]->next=NULL; 
	} 
	
	while(1){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		if(x==-1 || y==-1 || w==-1)break;
		GM[x][y]=w; // 邻接矩阵的输入 
		
//		// 邻接表的输入 (单链表的插入)
//		GNode p = GT[x];
//		while(p->next)p=p->next; // 找到插入位置的前一个节点
//		GNode q = (GNode)malloc(sizeof(GNode));
//		q->v=y,q->w=w,q->next=NULL;
//		p->next=q;
	}
	
	for(i=1;i<N;i++){
		for(j=1;j<N;j++){
			printf("%6d ",GM[i][j]);
		}
		printf("\n");
	}
	


	// 把邻接矩阵转换为邻接表
	for(i=1;i<N;i++){
		for(j=1;j<N;j++){
			if(GM[i][j]==0 || GM[i][j]==INF)continue;
			GNode p = GT[i];
			while(p->next)p=p->next;
			GNode q = (GNode)malloc(sizeof(GNode));
			q->v=j,q->w=GM[i][j],q->next=NULL;
			p->next=q;
		}
	} 
	
	printf("====================\n");
	for(i=1;i<N;i++){
		GNode p = GT[i]->next;
		printf("结点%d  -> ",i);
		while(p){
			printf("|%2d|%2d| -> ",p->v,p->w);
			p=p->next;
		}
		printf("NULL\n");
	}
	return 0;
}

