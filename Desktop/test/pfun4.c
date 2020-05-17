#include <stdio.h>

char *itoa(char *p, int n);

int main(int argc, const char *argv[])
{
	int n;
	char s[50], *r;

	printf("input:");
	scanf("%d", &n);

	r=itoa(s, n);
	puts(r);
	puts(s);
	
	return 0;
}

char *itoa(char *p, int n)
{
	int r, i=0, j;
//	static char p[50];

	while(n)
	{
		r=n%10;
		n/=10;
		p[i]=r+'0';
		i++;
	}
	p[i]='\0';

	j=i-1;
	i=0;

	while(i<j)
	{
		r=p[i];
		p[i]=p[j];
		p[j]=r;
		i++;
		j--;
	}

	return p;
}
