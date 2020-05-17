#include <stdio.h>

char *mstrcat(char *dest, const char *src);

int main(int argc, const char *argv[])
{
	char dest[50]="welcome";
	char src[]="makeru";

	puts(mstrcat(dest, src));
	puts(dest);
	
	return 0;
}

char *mstrcat(char *dest, const char *src)
{
	char *r=dest;

	while(*dest)
	{
		dest++;
	}

	while(*src)
	{
		*dest=*src;
		dest++;
		src++;
	}
	*dest='\0';

	return r;
}
