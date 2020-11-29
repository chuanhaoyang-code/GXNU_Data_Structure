#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}*LinkList;

double get_avg(LinkList L){
	int sum=0,len=0; // s:ºÍ  len: ³¤¶È
	LinkList p = L->next;
	while(p){
		sum = sum + p->data;
		len = len + 1;
		p=p->next; 
	}
	return sum*1.0/len*1.0;
}


int main(){
	LinkList L = (LinkList)malloc(sizeof(LinkList)); 
	LinkList x1 = (LinkList)malloc(sizeof(LinkList)); 
	LinkList x2 = (LinkList)malloc(sizeof(LinkList)); 
	LinkList x3 = (LinkList)malloc(sizeof(LinkList)); 
	L->data=-1,x1->data=1,x2->data=3,x3->data=9;
	L->next=x1,x1->next=x2,x2->next=x3;x3->next=NULL;
	
//	LinkList p = L->next;
//	
//	while(p){
//		printf("%d ",p->data);
//		p=p->next;
//	}
	double res = get_avg(L);
	printf("%.1lf\n",res);
	return 0;
}

 
