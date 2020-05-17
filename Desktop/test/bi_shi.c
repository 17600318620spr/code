#include <stdio.h>

void swap(char *a, char *b)
{
	char tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

int main(int argc, const char *argv[])
{
	char array[20]="Hello World";
//	array="Hello World";

	char str1='A', str2='B';
	char *p1=&str1, *p2=&str2;

//	char *p1="A", *p2="B";

//	swap(p1, p2);
	swap(&str1, &str2);

	printf("%d %d", str1, str2);
	
	return 0;
}
