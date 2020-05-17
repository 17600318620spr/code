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
	double y, ret;
	int m;
//	double ret;

	printf("input:");
	scanf("%lf%d", &y, &m);

	ret=power(y, m);
//	ret=power(2, 3);

	printf("%lf %d=%lf\n", y, m, ret);
//	printf("%lf\n", ret);
	
	return 0;
}
