#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}*LinkList,LNode; 

int find_max(LinkList L){
	LinkList p=L->next;
	int res=p->data; // 假设第一个数是最大的 
	while(p){  
		if(res<p->data)res=p->data;
		p=p->next; // p要往后走 
	}
	
	return res;
}

int main(){ // 考试可以不用写主函数 
	LinkList L = (LinkList)malloc(sizeof(LinkList));
	LinkList x1 = (LinkList)malloc(sizeof(LinkList));
	LinkList x2 = (LinkList)malloc(sizeof(LinkList));
	LinkList x3 = (LinkList)malloc(sizeof(LinkList));
	L->data=-1,x1->data=1,x2->data=3,x3->data=9;
	L->next=x1,x1->next=x2,x2->next=x3,x3->next=NULL;
	
//	LNode *p = L->next; 
//	while(p){
//		printf("%d ",p->data);
//		p=p->next;
//	}
	
	int res= find_max(L);
	printf("%d\n",res);
	return 0;
} 
