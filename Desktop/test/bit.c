#include <stdio.h>

int main(int argc, const char *argv[])
{
	unsigned char x=0xe4, y=1;

	printf("x=%#x, y=%#x\n", x, y);

	y=x<<3;
	printf("x=%#x, y=%#x\n", x, y);
	
	return 0;
}
