#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next; 
}LNode,*LinkList;

// L: 带有头节点的单链表
// x: 要删除的元素 
void del(LinkList L,int x){
	LNode *p = L;
	while(p){
		// 找到x的前一个结点
		if(p->next && p->next->data==x){
			break;
		} 
		p=p->next;
	} 
	
	if(p){
		LinkList q = p->next;
		p->next = q->next;
		free(q);
	}
}


int main(){
	LinkList L = (LinkList)malloc(sizeof(LinkList));
	LinkList x1 = (LinkList)malloc(sizeof(LinkList));
	LinkList x2 = (LinkList)malloc(sizeof(LinkList));
	LinkList x3 = (LinkList)malloc(sizeof(LinkList));
	L->data=-1,x1->data=1,x2->data=3,x3->data=9;
	L->next=x1,x1->next=x2,x2->next=x3,x3->next=NULL;
	
	del(L,11);
	
	LinkList p = L->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	
	return 0;
}


