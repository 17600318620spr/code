#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[3][2]={{1, 6}, {9, 12}, {61, 12}};
	int (*p)[2], i, j;

	p=a;
	printf("%p %p\n", a, a+1);
	printf("%p %p\n", p, p+1);

	for(i=0; i<3; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%d %d %d %d\n", p[i][j], a[i][j], *(*(a+i)+j), *(*(p+i)+j));
		}
		puts("");
	}
	
	return 0;
}
