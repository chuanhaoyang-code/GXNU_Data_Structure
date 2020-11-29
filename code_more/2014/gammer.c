#include<stdio.h>

int main(){
//	char c='\n',d='\t',e='\\'; // \n 回车  \t TAB  转义字符 
//	int x,y;
//	scanf("%d%d",&x,&y); // scanf会过滤空格  %d %d  | %d%d | %d,%d 
//	printf("x: %d\ny: %d\n",x,y);
//	char c;
//	scanf("%c",&c);
//	if(c>='a' && c<='z')printf("yes");
//	else printf("no");
	// 指针(地址变量)  数组名就是地址 
//	char strc[]=" ABCDEFG"; // 长度9 有效字符为8
//	printf("%c==\n",*strc); 
//	printf("%c\n",*(strc+4));
//	printf("%p\n",strc);
//	printf("%p\n",strc+1);
//	// %s 从指针的开头 \0
//	printf("%s\n",strc);
//	printf("%s\n",strc+1);
//	printf("%s\n",strc+2); 

//	int a[10]={1,2,3,4,5,6,7,8,9,10}; // int 4个字节 
//	int *p=a;
//	// %p 格式化输出指针 
//	printf("%p\n",p);
//	printf("%p\n",p+1);
//	printf("%p   %p\n",p+5,a+5); 
//	printf("%d   %d\n",*(p+5),a[5]);  // p+5=a+5  *(p+5)=a[5]
	int q[11]={1,4,6,9,13,16,19,28,40,45}; // 最后一个数为0 
	int len = sizeof(q)/sizeof(int);
	printf("%d\n",len);
	int i;
	for(i=0;i<11;i++)printf("%d ",q[i]);
	return 0;
} 
