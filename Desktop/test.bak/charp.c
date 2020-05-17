#include <stdio.h>
#include <ctype.h>

int main(int argc, const char *argv[])
{
	char ch1[]="Hello world!";
	char ch2[]="Hello world!";
	char *p;

	p=ch1;
	if(isalpha(*p))
	{
		if(isupper(*p))
			*p=tolower(*p);
		else
			*p=toupper(*p);
	}
	puts(p);

	p=ch2;
	printf("%s\n", p);
	
	return 0;
}
