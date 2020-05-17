#include <stdio.h>

int main(int argc, const char *argv[])
{
	char ch[50]="welcome";
	char *p="hello world!", *q;
	int i=0;

	q=p;

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
	*(ch+i)='\0';

//	p=q;

	puts(ch);
	puts(p);
	puts(q);

	return 0;
}
