#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next; 
}LNode,*LinkList;

void swap_link(LinkList L){
	LinkList p = L->next; 
	LinkList q = p;// q是指向最大值结点的指针 
	// 找到最大值的结点 
	while(p){
		if(p->data>q->data)q=p;
		p=p->next; 
	}
	// 交换 
	p=L->next;
	int t=p->data;
	p->data=q->data,q->data=t;
}

void create(LinkList L){
	L->data=-1,L->next=NULL;
	LinkList p = L; 
	while(1){
		int t;
		scanf("%d",&t);
		if(t==-1)break;
		LinkList q = (LinkList)malloc(sizeof(LinkList));
		q->data=t,q->next=NULL;
		p->next=q;
		p=p->next;
	}
}
int main(){
	LinkList L = (LinkList)malloc(sizeof(LinkList));
	create(L);
	swap_link(L);
	
	LinkList p = L->next;
	while(p){
		printf("%d ",p->data);
		p=p->next; 
	}
	
	return 0;
} 
