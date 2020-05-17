#include <stdio.h>

typedef union 
{
    unsigned long int i;      // 或 int i
    unsigned char s[4];
} IS4;
 
int main(int argc, const char *argv[])
{
	IS4 x;
	printf("%d\n", sizeof(x.i));                           //32 位整数
	printf("%d %d\n", sizeof(x.s[0]), sizeof(x.s[1]));     //高（或低）16位
	printf("%d %d\n", sizeof(x.s[2]), sizeof(x.s[3]));     //低（或高）16位

	return 0;
}
