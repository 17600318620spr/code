#include <stdio.h>

int main(int argc, const char *argv[])
{
	int *p[3];//int * ------ p[0] p[1] p[2]
	int a[]={3, 6, 1, 9, 10};

	p[0]=a;
	p[1]=a+1;
	p[2]=a+3;

	printf("%d %d %d\n", a[0], a[1], a[3]);
	printf("%d %d %d\n", *p[0], *p[1], *p[2]);
	
	return 0;
}
