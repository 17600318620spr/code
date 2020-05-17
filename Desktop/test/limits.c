#include <stdio.h>
#include <limits.h>

int main(int argc, const char *argv[])
{
	printf("char :%d-%d\n", CHAR_MIN, CHAR_MAX);
	printf("short:%d-%d\n", SHRT_MIN, SHRT_MAX);
	printf("int  :%d-%d\n", INT_MIN, INT_MAX);
	
	return 0;
}
