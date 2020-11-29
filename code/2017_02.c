#include<stdio.h>
#include<string.h>
/*
除数 / 被除数 = 商 ... 余数
...
              = 0  ... 余数(结束) 

*/

// 非递归 
int f1(int x){
	char path[100];
	int k=0; 
	while(x){
		int a = x/2;
		int b=x%2; // a:商 b:余数
		path[k++]=(b+'0'); 
		x=a; // 下一个除数是商 
	}
	while(k>=0)printf("%c",path[--k]);
} 

// 递归
void f2(int x){
	int a=x/2,b=x%2;
	if(a==0){
		printf("%d",b);
		return;
	}
	f2(a),printf("%d",b);
} 
int main(){
	f1(15);
	printf("\n");
	f2(15);
	return 0;
} 
