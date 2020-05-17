#include <stdio.h>

int main(int argc, const char *argv[])
{
	char *p1="hello world!";
	char *p2="hello world!";

//	*p1-=32;//error

	printf("&p1=%p %p %s\n", &p1, p1, p1);
	printf("&p2=%p %p %s\n", &p2, p2, p2);
	
	return 0;
}
