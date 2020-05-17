#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[6], i;

//	for(i=0; i<6; i++)
//	{
//		printf("%p\n", &a[i]);
//	}

	for(i=5; i>=0; i--)
	{
		printf("%p\n", &a[i]);
	}

//	a=a+1;
	printf("a=%p\n", a);
	printf("%d\n", sizeof(a));
	
	return 0;
}
