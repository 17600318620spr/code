#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a=10;
	int *p;

	p=&a;

	printf("&p:%p %d\n", &p, sizeof(p));
	printf("%p %p\n", p, &a);
	printf("%d %d\n", a, *p);
	
	return 0;
}
