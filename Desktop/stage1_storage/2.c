#include <stdio.h>

int main(int argc, const char *argv[])
{
	char s[64];
	int a=12345678;

	sprintf(s,"%d\n",a);

//	fprintf(stdout, "%d\n", a);
	printf("s=%s\n", s);

	return 0;
}
