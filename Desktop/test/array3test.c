#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[2][3]={{2, 5, 8}, {21, 56, 9}};
	int i, j, row=0, column=0;

	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			if(a[row][column]<a[i][j])
			{
				row=i;
				column=j;
			}
		}
	}
	printf("%d %d %d\n", a[row][column], row, column);

	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ", a[i][j]);
		}
		puts("");
	}
	
	return 0;
}
