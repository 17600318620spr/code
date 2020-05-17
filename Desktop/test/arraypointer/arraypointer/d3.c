#include <stdio.h>

#define N 5

int main(int argc, const char *argv[])
{
	int a[N];
	int *p, i;

	p=a;//int *p=a;
	
	for(i=0; i<N; i++)
	{
		scanf("%d", p++);//&a[i]
	}
//	printf("\n");

	p=a;
	for(i=0; i<N; i++)
	{
		printf("%d ", *p);//*p++
		p++;
	}
	puts("");
	
	return 0;
}
