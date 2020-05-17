#include <stdio.h>

int main(int argc, const char *argv[])
{
	int m=10;
	double n=3.14;
	void *p, *q;

	p=&m;//(void *)&m;
	printf("%d %d\n", m, *(int *)p);
printf("%p\n", p);
p++;
printf("%p\n", p);

	q=&n;//(void *)&n;
	printf("%.2lf %.2lf\n", n, *(double *)q);
printf("%p\n", q);
q++;
printf("%p\n", q);
	
	return 0;
}
