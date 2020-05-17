#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char ch[50]="welcome";
	char *p="hello world!";

	printf("%p %p\n", p, ch);

	strcpy(ch, p);
//	strcpy(p, ch);

	printf("%p %p\n", p, ch);

	puts(ch);
	puts(p);
	
	return 0;
}
