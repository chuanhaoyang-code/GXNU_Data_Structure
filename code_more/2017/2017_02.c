#include<stdio.h>

int path[100];
int k=0;

// ·ÇµÝ¹é 
void f1(int x){
	int a,b;
	do{
		a=x/2,b=x%2;
		path[k++]=b;
	
//		printf("%d ... %d\n",a,b);
		x = a;
	}while(a!=0);
}

void f2(int x){
	int a=x/2,b=x%2;
	if(a==0){

		printf("%d ",b);
		return;
	}
	f2(a),printf("%d ",b);
}

int main(){
	f2(100);
//	int i=k-1;
//	for(i=k-1;i>=0;i--)printf("%d ",path[i]);
	return 0;
}
