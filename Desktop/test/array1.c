#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[2][3];
	int i, j;

	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%p ", &a[i][j]);
		}
		putchar('\n');
	}

//	a[0]++;
//	a[1]++;

	printf("%p %d\n", a, sizeof(a));
	printf("%p %d\n", a[0], sizeof(a[0]));
	printf("%p %d\n", a[1], sizeof(a[1]));
	
	return 0;
}
