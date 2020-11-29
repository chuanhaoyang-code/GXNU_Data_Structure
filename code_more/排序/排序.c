#include<stdio.h>

int q[] ={10,3,9,2,8,9,1};
int len = sizeof(q)/sizeof(int);

void bubble_sort(int q[],int l,int r){
	if(l>=r)return;
	int i,j;
	for(i=0;i<7;i++){// 每次从无序组选最大放在有序组 
		for(j=0;j+1<7-i;j++){
			if(q[j]>q[j+1]){
				int t=q[j];
				q[j]=q[j+1],q[j+1]=t;
			}
		}	
	}

	for(i=0;i<len;i++)printf("%d ",q[i]); 
}

void select_sort(int q[],int l,int r){
	if(l>=r)return;
	int min,i=0,j; // min 最小数的下标
	for(i=0;i<7;i++){
		min=i; // 假设每次无序组的第一个数最小 
		for(j=i;j<7;j++){
			if(q[min]>q[j])min=j;
		}
		// 把当前无序组最小的数放到i这个位置上 
		int t=q[min];
		q[min]=q[i];
		q[i]=t;
	} 

	for(i=0;i<len;i++)printf("%d ",q[i]); 
}

void insert_sort(int q[],int l,int r){
	if(l>=r)return;
	int i,j;
	for(i=1;i<7;i++){// 枚举到有序组的第i个位置 
		j=i;
		while(j-1>=0 && q[j]<q[j-1]){
			// 交换 
			int t=q[j-1];
			q[j-1]=q[j],q[j]=t; 
			j--;
		}
	}
	for(i=0;i<len;i++)printf("%d ",q[i]); 
} 

// 快排有很多边界的问题 
void quick_sort(int q[],int l,int r){
	if(l>=r)return; 
	// 进行以 x 分界点进行划分      
	//   <x    x   >x 
	int i=l-1,j=r+1,x=q[l];
	while(i<j){
		while(q[++i]<x);
		while(q[--j]>x);
		if(i<j){
			int t=q[i];
			q[i]=q[j],q[j]=t;
		}
	}
	quick_sort(q,l,j);// 对左子数组边进行处理
	quick_sort(q,j+1,r); // 对右子数组进行处理 
} 

void merge_sort(int q[],int l,int r){
	if(l>=r)return;
	int mid=(l+r)/2;
	merge_sort(q,l,mid); // 进行左边的划分
	merge_sort(q,mid+1,r); // 进行右边的划分
	
	// 两个有序数组合并成一个有序数组
	int i=l,j=mid+1,k=0,tmp[100];
	while(i<=mid && j<=r){ // 结束条件是有一个指针已经遍历完了 
		if(q[i]<=q[j]){
			tmp[k++]=q[i++];
		}else{
			tmp[k++]=q[j++];
		}
	} 
	// 收尾
	while(i<=mid)tmp[k++]=q[i++]; 
	while(j<=r)tmp[k++]=q[j++];
	// tmp是合并好的大数组   
	// tmp => q 
	for(i=l,j=0;i<=r;i++,j++)q[i]=tmp[j];
	 
} 


int main(){

	int i;
	for(i=0;i<len;i++)printf("%d ",q[i]);
	printf("\n========\n");
//	bubble_sort(q,0,len-1);
//	select_sort(q,0,len-1);
//	insert_sort(q,0,len-1);
//	quick_sort(q,0,len-1);
	merge_sort(q,0,len-1); 
	for(i=0;i<len;i++)printf("%d ",q[i]); 
	return 0;
} 
