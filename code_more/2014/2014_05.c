#include<stdio.h>

double to_c(double f){
	return 5.*(f-32)/9.;
}

int main(){
	double f,c;
	scanf("%lf",&f);
	c = to_c(f);
	printf("%.2lf\n",c);
	return 0;
}
