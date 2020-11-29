#include<stdio.h>

// 非递归 
int bsearch1(int q[],int l,int r,int x){
	while(l<=r){ // <=     
		int mid = (l+r)/2; 
		if(q[mid]==x)return mid;
		else if(q[mid]>x)r=mid-1;  
		else l=mid+1;
	}
	return -1;
} 

// 递归
int bsearch2(int q[],int l,int r,int x){
	if(l>r)return -1; 
	int mid = (l+r)/2;
	if(q[mid]==x)return mid;
	else if(q[mid]>x)return bsearch2(q,l,mid-1,x); 
	else return bsearch2(q,mid+1,r,x);
	
} 

int main(){
	// 二分查找的前提是有序 
	int q[] = {1,2,3,4,5,6,7,8};
	int x=8;
	printf("%d\n",bsearch1(q,0,8-1,x));
	printf("%d\n",bsearch2(q,0,8-1,x));
	
	return 0;
}

