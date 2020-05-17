#include <stdio.h>
#include <stdint.h>
//#include <stdlib.h>

int main(int argc, const char *argv[])
{
	uint32_t aa;
	int32_t bb;
	int cc;

	printf("%d\n", sizeof(aa));
	printf("%d\n", sizeof(bb));
	printf("%d\n", sizeof(cc));
	printf("sizeof(short)=%d\n", sizeof(short));
	printf("sizeof(long)=%d\n", sizeof(long)); //what!!!
	printf("sizeof(double)=%d\n", sizeof(double));

	return 0;
}
