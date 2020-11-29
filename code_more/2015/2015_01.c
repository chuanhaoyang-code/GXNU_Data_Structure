#include<stdio.h>
#include<stdlib.h>
/*
1. typedef struct 
2. 头插入/删除
3. 头节点 
*/

typedef struct node{
	int data;
	struct node *next;
}Bnode;

// head: 头节点的地址 
// x: 要插入的值
// i: 要插入的位置 
void insert(Bnode* head,int x,int i){
	Bnode *p = head; // 不能动head,否则会找不链表
	int j=1;
	// 找到要插入位置的前一个结点 
	while(j<i){ // 停下来的时候,j==i ==> i-1 
		p=p->next;
		j++;
	} 
	// 给x创建一个新结点
	Bnode *q = (Bnode*)malloc(sizeof(Bnode)); // malloc 和系统要一个空间 
	q->data=x;q->next=NULL;
	// 插入的顺序很重要! 
	q->next=p->next;
	p->next=q;
}
 

int main(){ // 考试不用写main 
	Bnode* head = (Bnode*)malloc(sizeof(Bnode));
	Bnode* l1 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* l2 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* l3 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* l4 = (Bnode*)malloc(sizeof(Bnode));
	Bnode* l5 = (Bnode*)malloc(sizeof(Bnode));
	
	// 开始赋值
	head->data=-1,l1->data=1,l2->data=3,l3->data=9,l4->data=8,l5->data=20; 
	head->next=l1,l1->next=l2,l2->next=l3,l3->next=l4,l4->next=l5,l5->next=NULL; 
	insert(head,100,2);
	
	Bnode *p = head;
	while(p->next!=NULL){
		printf("%d ",p->next->data);
		p=p->next;
	}
	
	return 0;
} 







