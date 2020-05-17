#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a=10, *p;
	double b=3, *q;

	p=&a;
	q=&b;

	printf("%p %p\n", p, p+2);
	printf("%p %p\n", q, q+2);
	
	return 0;
}
