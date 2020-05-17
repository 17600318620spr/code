#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[2][3]={{1, 4, 6}, {12, 9, 7}};//a-----a[0]  a[1]
	int *p[2];

	p[0]=a[0];//&a[0][0]
	p[1]=a[1];//&a[1][0]

	printf("%d\n", a[0][1]);
	printf("%d\n", *(a[0]+1));
	printf("%d\n", *(p[0]+1));

	printf("%d\n", *(p[1]+2));
	
	return 0;
}
