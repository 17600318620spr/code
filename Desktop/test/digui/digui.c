#include <stdio.h>

int fac(int n);

int main(int argc, const char *argv[])
{
	int n;

	printf("input:");
	scanf("%d", &n);

	printf("%d\n", fac(n));

	return 0;
}

int fac(int n)
{
	if(n==0 || n==1)
		return 1;

	return n*fac(n-1);
}
