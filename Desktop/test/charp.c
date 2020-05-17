#include <stdio.h>
#include <ctype.h>

int main(int argc, const char *argv[])
{
	char ch1[]="Hello world!";
	char ch2[]="Hello world!";
	char *p;

	p=ch1;//ch1[0]----*(ch+0)----p[0]----*p
	if(isalpha(*p))
	{
		if(isupper(*p))
			*p=tolower(*p);
		else
			*p=toupper(*p);
	}
//	puts(p);
	printf("%p %s\n", p, p);

	p=ch2;
	printf("%p %s\n", p, p);
	
	return 0;
}
