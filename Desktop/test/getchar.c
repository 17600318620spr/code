#include <stdio.h>

int main(int argc, const char *argv[])
{
	int ch;

	printf(">");

	ch=getchar();

	putchar(ch);
	putchar('\n');

	printf("ch=%d\n", ch);
	
	return 0;
}
