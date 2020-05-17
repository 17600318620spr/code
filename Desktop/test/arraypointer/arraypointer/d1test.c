#include <stdio.h>

int main(int argc, const char *argv[])
{
	char a='b';
	char b=' ';
	char *p;
	char *q;
	int c=10;
	int d=20;

//	p=&a;

//	printf("%p %p\n", p, &a);
	printf("%p %p\n", &a, &b);
	printf("%p %p\n", &c, &d);
	printf("&p:%p &q:%p\n", &p, &q);
	
	return 0;
}
