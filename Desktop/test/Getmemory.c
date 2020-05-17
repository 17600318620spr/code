#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *gm(void)
{
//	static char p[]="hello world";
	char p[]="hello world";
	return p;
}


/*
char *gm(void)
{
	char *p="hello world";
	return p;
}
*/

int main(void)
{
	char *str=NULL;
	str=gm();
	
	puts(str);
}
