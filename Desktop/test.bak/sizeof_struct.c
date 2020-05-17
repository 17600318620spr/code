#include <stdio.h>

//#pragma pack(2)
/*
	struct A
	{
		char b;
		int a;
		short c;
	};
*/

int main(int argc, const char *argv[])
{
	struct B
	{
		char b;
		int a;
		short c;
		double d;
	}p;


//	printf("%d\n", sizeof(struct A));
	printf("%d\n", sizeof(struct B));
	printf("b=%d\n", sizeof(p.b));
	printf("a=%d\n", sizeof(p.a));
	printf("c=%d\n", sizeof(p.c));
	printf("d=%d\n", sizeof(p.d));
	
	return 0;
}


