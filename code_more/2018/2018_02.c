#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next; 
}*LinkList;

// 最后LA是 LA和LB的合并且去重的逆序链表 
void merge_link(LinkList LA,LinkList LB){ //LA和LB都是带有头节点 
	// 1. 把LB和合并LA后面 
	LinkList p=LA,q;
	while(p->next)p=p->next; // 找到LA最后一个结点
	p->next=LB->next; 
	// 2. 逆序
	p=LA->next;
	while(p){
		q = p->next;
		while(q){
			if(p->data<q->data){
				int t=p->data;
				p->data=q->data;
				q->data=t;
			}
			q = q->next;
		}
		p=p->next;
	} 
	// 3. 去重
	p=LA->next;
	while(p){
		q=p;
		while(q){
			if(q->next && q->next->data==p->data){
				q->next = q->next->next;
				// 要注意,不能让q往后走 
				continue; 
			}
			q=q->next;
		}
		p=p->next;
	} 
	
}


// 传入头结点,创建单链表 
LinkList create(LinkList L){// L: 头节点 
	L->data=-1,L->next=NULL;
	LinkList p = L;
	while(1){
		int t;
		scanf("%d",&t);
		if(t==-1)break; 
		LinkList q = (LinkList)malloc(sizeof(LinkList));
		q->data=t;
		q->next=NULL;
		p->next=q;
		p=p->next;
	}
	return L;
}

// 逆序排序 
void link_sort(LinkList L){
	LinkList p,q;
	p=L->next;
	while(p){
		q = p->next;
		while(q){
			if(p->data<q->data){
				int t=p->data;
				p->data=q->data;
				q->data=t;
			}
			q = q->next;
		}
		p=p->next;
	}
} 


void del(LinkList L){
	LinkList p=L->next,q;
	while(p){
		q=p;
		while(q){
			if(q->next && q->next->data==p->data){
				q->next = q->next->next;
				// 要注意,不能让q往后走 
				continue; 
			}
			q=q->next;
		}
		p=p->next;
	}
	
}


int main(){
	LinkList LA = (LinkList)malloc(sizeof(LinkList));
	LinkList LB = (LinkList)malloc(sizeof(LinkList));
	create(LA);
	create(LB);
	merge_link(LA,LB);
	// 打印 
	LinkList pa = LA->next;
	while(pa){
		printf("%d ",pa->data);
		pa=pa->next;
	}
	return 0;
}
