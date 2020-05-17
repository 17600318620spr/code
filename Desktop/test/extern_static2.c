#include <stdio.h>

extern int global_a;

int main(int argc, const char *argv[])
{
	printf("global_a=%d\n", global_a);
	
	return 0;
}
