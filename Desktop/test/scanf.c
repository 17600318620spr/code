#include <stdio.h>

int main(int argc, const char *argv[])
{
	int ch, n;

	printf(">");

	n=scanf("%x", &ch);

	printf("%d %d\n", n, ch);
	
	return 0;
}
