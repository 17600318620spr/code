#include <stdio.h>

int main(int argc, const char *argv[])
{
	char ch[100]="welcome";
	char *p="hello world";
	int i=0;

	while(*(ch+i))
	{
		i++;
	}

	while(*p)
	{
		*(ch+i)=*p;
		i++;
		p++;
	}
//	*(ch+i)='\0';
	*(ch+i)=*p;

	puts(ch);
	puts(p);
	
	return 0;
}
