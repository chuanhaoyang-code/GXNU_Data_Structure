#include<stdio.h>

/*
思路: 找到应该插入的位置,然后把其他数向后移动
找插入的位置插入该数 

*/

int main(){
	int a[11]={1,4,6,9,13,16,19,28,40,45};	// 多一个位置,最后一个位置为0 
	int x;
	scanf("%d",&x);
	int i=0; // 要插入的位置
	while(i<10 && a[i]<=x)i++; // i停下来的时候a[i]>x 或者 到了边界 
	if(i==10)a[10]=x;
	else{ // 否则 下标[i,9]都需要向后移动一位 
		int j;
		for(j=10;j>i;j--){
			int t=a[j];
			a[j]=a[j-1];
			a[j-1]=t;
		}
		a[i]=x;
	} 
	for(i=0;i<11;i++)printf("%d ",a[i]);
	return 0;
}
