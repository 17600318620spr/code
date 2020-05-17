#include <stdio.h>

char *del_space(char *s);

int main(int argc, const char *argv[])
{
	char *r;
	char str[]="   how  are you  ";

	r=del_space(str);
	printf("---%s---\n", r);

	puts(str);
	
	return 0;
}

char *del_space(char *s)
{
	//char *r=s;
	char *p=s;
	char *r=p;

	while(*s)
	{
		if(*s==' ')
		{
			s++;
		}
		else
		{
			*p=*s;
			s++;
			p++;
		}
	}
	*p='\0';

	return r;
}
