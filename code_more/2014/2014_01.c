#include<stdio.h>  
#include<math.h>

/*
math.h
sin() cost() sqrt()
*/

#define PI 3.1415926 

int main(){
	int v0=2,t;
	double sita=PI/3,g=9.8;
	scanf("%d",&t);
	double v,vx,vy;
	vx = v0*cos(sita);
	vy = v0*sin(sita)-g*t;
	v = sqrt(vx*vx+vy*vy);
	printf("%.2lf\n",v);
	
	return 0;
}







