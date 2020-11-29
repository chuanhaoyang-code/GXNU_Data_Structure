#include<stdio.h>

int main(){
	int s=0,i;
	for(i=1;i<=100;i++)
		if(i%2!=0)s+=i;
	printf("%d\n",s);
	return 0;
}
