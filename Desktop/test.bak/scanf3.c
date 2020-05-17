#include <stdio.h>

int main(int argc, const char *argv[])
{
	int x;
	char ch;

	scanf("%d", &x);
	getchar();
//	getchar();
	ch=getchar();
//	scanf("%c", &ch);
	printf("x=%d, ch=%d\n", x, ch);
	
	return 0;
}
