#include<stdio.h>
#include<stdlib.h>

typedef struct TNode{
	char data;
	struct TNode * lchild;
	struct TNode * rchild;
}*TNode;


// C是没有bool类型的, int


int  is_same(TNode a,TNode b){ // 1:相等  0: 不相等 
	if(a==NULL && b==NULL)return 1;
	if(a==NULL && b!=NULL)return 0;
	if(a!=NULL && b==NULL)return 0;
	if(a!=NULL && b!=NULL){ // 使用先序进行判断 
		if(a->data == b->data){
			return is_same(a->lchild,b->lchild) && is_same(a->rchild,b->rchild);
		} else{
			return 0;
		}
	}
} 

// 按照先序来创建 
TNode create(){
	TNode T;
	char ch;
	scanf("%c",&ch);
	if(ch=='#')T=NULL;
	else{
		T = (TNode)malloc(sizeof(TNode)); // 分配一个空间
		T->data = ch;
		T->lchild = create();
		T->rchild = create(); 
	}
	return T;
}

// 按照先序来遍历
void root_first(TNode T){
	if(T==NULL)return;
	printf("%c ",T->data);
	root_first(T->lchild);
	root_first(T->rchild);
	
} 

int main(){
	TNode a = create();  
	root_first(a); 
	printf("\n");
	getchar(); //吃掉回车
	TNode b = create();   
	root_first(b);
	printf("\n");
	int res = is_same(a,b);
	printf("%d\n",res);
	
	return 0;
}


