#include<stdio.h>
#include<stdlib.h> 

typedef struct node{
	int data;
	struct node *next;
}Bnode;

void insert(Bnode *head,int i,int x){ // 在第i个位置插入x
	Bnode *p = head; 
	int j;
	for(j=1;j<i;j++)p=p->next; // p停下来在i-1 
	Bnode *q = (Bnode*)malloc(sizeof(Bnode));
	q->data=x;
	// 注意插入的顺序 
	q->next=p->next;
	p->next=q;
}

int main(){
	// 做几个测试
	Bnode* head = (Bnode*)malloc(sizeof(Bnode));
	Bnode* l1 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* l2 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* l3 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* l4 = (Bnode*)malloc(sizeof(Bnode));
	head->data=-1;l1->data=1;l2->data=3;l3->data=9;l4->data=2;
	head->next=l1;l1->next=l2;l2->next=l3;l3->next=l4;l4->next=NULL;
	
	Bnode *p=head->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	} 
	insert(head,2,10);
	printf("\n");
	p=head->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	} 
	return 0;
} 
