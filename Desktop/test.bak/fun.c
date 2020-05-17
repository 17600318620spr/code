#include <stdio.h>

double power(double x, int n)
{
	double r=1;
	int i;

	for(i=1; i<=n; i++)
	{
		r*=x;
	}

	return r;
}

int main(int argc, const char *argv[])
{
	double x, ret;
	int n;

	printf("input:");
	scanf("%lf%d", &x, &n);

	ret=power(x, n);

	printf("%lf %d=%lf\n", x, n, ret);
	
	return 0;
}
