#include <stdio.h>

int f(int m, int n)
{
	if(m*n==0)
		return m+n+1;

	return f(m-1, f(m, n-1));
}

int main(int argc, const char *argv[])
{
	printf("%d\n", f(2, 2));
	
	return 0;
}
