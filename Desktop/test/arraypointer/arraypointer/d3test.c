#include <stdio.h>

#define N 5
int main(int argc, const char *argv[])
{
	int a[N];
	int i, *p;

	p=a;
	for(i=0; i<N; i++)
	{
		scanf("%d", &a[i]);
//		p++;
	}

//	p=a;
	for(i=0; i<N; i++)
	{
		printf("%d ", *p++);
	}
	putchar(10);
	
	return 0;
}
