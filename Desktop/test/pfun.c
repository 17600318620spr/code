#include <stdio.h>
#include <string.h>

char *getstring()
{
	//char str[20];//error
	//static char str[20];
	char *str="hello";

	//strcpy(str, "hello");

	return str;
}

int main(int argc, const char *argv[])
{
	char *r;

	r=getstring();
	printf("---%s---\n", r);

	//(*r)++;
	puts(r);

	return 0;
}
