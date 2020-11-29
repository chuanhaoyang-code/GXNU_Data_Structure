#include<stdio.h>

#define m 5 

// A ×ªÖÃÎª B 
void T(int A[m][m],int B[m][m]){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			B[j][i]=A[i][j];
		}
	}
}


int main(){
	int A[m][m]={0},B[m][m]={0};
	int i,j;
	for(i=0;i<m*m;i++){
		A[i/m][i%m]=i+1;
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n===========\n");
	T(A,B);
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				printf("%d ",B[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}


