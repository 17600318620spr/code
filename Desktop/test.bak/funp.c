#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int mul(int a, int b)
{
	return a*b;
}

int main(int argc, const char *argv[])
{
	int m=10, n=20;
	int (*p)(int, int);

	p=add;
//	printf("%d\n", add(m, n));
	printf("%d\n", (*p)(m, n));
	
	p=sub;
	printf("%d\n", (*p)(m, n));

	return 0;
}
