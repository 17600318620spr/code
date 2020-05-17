#include <stdio.h>
int main() 
{ 
	float F(int m,int n); 
	int n,m; 
	float y; 
	
	printf("请输入两个数据:\n"); 
	scanf("%d%d",&m,&n); 
	
	y=F(m,n); 
	printf("F(%d,%d)=%f\n",m,n,y); 

	return 0; 
} 

float F(int m,int n) 
{ 
	float y; 
	
	if(n==1) y=m; 
	else if(m==1) y=n; 
	else y=F(m-1,n)+F(m,n-1); 
	
	return y; 
}
