#include <stdio.h>

int main(int argc, const char *argv[])
{
	//int a[2][3]={{1, 6, 9}, {2, 8, 5}};
	int a[][3]={{1}, {2, 3}, {4}};
	int i, j;

	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}
	
	return 0;
}
