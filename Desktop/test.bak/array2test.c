#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[10][10];
	int i, j;

	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			a[i][j]=1;
		}
	}

	for(i=0; i<10; i++)
	{
		for(j=0; j<=i; j++)
		{
			printf("%d ", a[i][j]);
		}
		putchar(10);
	}
	
	return 0;
}
