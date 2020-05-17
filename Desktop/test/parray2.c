#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[2][3]={{1, 4, 6}, {12, 9, 7}};//a----a[0] a[1]
	int *p[2]={a[0], a[1]};
	int i, j, sum=0;

	int **q;
	q=p;//&p[0];

	printf("total:%d\n", sizeof(p));
	//printf("%p %p\n", p[0], a[0]);
	//printf("%p %p\n", p[1], a[1]);
	
	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			sum+=*(p[i]+j);
		}
	}
	printf("sum=%d\n", sum);

	return 0;
}
