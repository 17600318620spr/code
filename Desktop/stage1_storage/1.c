#include <stdio.h>


static char *reverse(char *s)
{
	char tmp;
	char *p=s;
	char *q=s;

	while(*q)
	{
//		++q;
		q++;
	}
	q--;

	while(q>p)
	{
		tmp=*p;
		*p++=*q;
		*q--=tmp;
	}

	return s;
}

static char *my_atoi(int n)
{
	static char s[100];
//	char s[100];
/*
	int i=0, isNeg=0;
	static char s[100];

	if((isNeg=n)<0)
	{
		n=-n;
	}

	do
	{
		s[i++]=n%10+'0';
		n=n/10;
	}while(n>0);

	if(isNeg<0)
	{
		s[i++]='-';
	}
	s[i]='\0';
*/
	sprintf(s,"%d\n",n);
	puts(s);
	puts("----------------------");
//	sprintf(s,"%d",n);

	return reverse(s);
}

int main(int argc, const char *argv[])
{
	int a=12345678;

	char *s=NULL;
	s=my_atoi(a);
	printf("s=%s\n", s);

	return 0;
}



/*
int main(int argc, const char *argv[])
{
	char a[]="asdfg";
	char *p=a;
	puts(p);

	p=reverse(a);
	puts(p);
	
	return 0;
}
*/
