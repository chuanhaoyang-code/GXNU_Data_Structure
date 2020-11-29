#include<stdio.h>
#include<stdlib.h>
/*
判断两颗二叉树是否相等很简单: 
只要采用一种遍历的方式,只要遍历出来的序列是相等,则说明两个二叉树相等 

*/

typedef struct TNode{
	char val;
	struct TNode *left,*right;
}*TNode;


// true:1   false:0 
int is_same(TNode a,TNode b){
	if(a==NULL && b==NULL)return 1; // 两个二叉树都为NULL 
	if((a==NULL && b!=NULL) || (a!=NULL && b==NULL))return 0;
	if(a->val==b->val){
		return is_same(a->left,b->left) && is_same(a->right,b->right);
	}else{
		return 0;
	}
} 

TNode create(){
	TNode T; 
	char ch;
	scanf("%c",&ch);
	if(ch=='#')T=NULL;
	else{
		T = (TNode)malloc(sizeof(TNode));
		T->val = ch;
		T->left = create();
		T->right = create();
	}
	return T; 
} 

void first_root(TNode T){
	if(T==NULL)return;
	printf("%c ",T->val);
	first_root(T->left);
	first_root(T->right); 
}

int main(){
	// 构建一棵二叉树 
	TNode T1 = create();
	getchar();
	TNode T2 = create();
	
	first_root(T1);
	printf("\n");
	first_root(T2);
	printf("\n");
	
	int res = is_same(T1,T2);
	printf("%d\n",res);
	return 0;
}


