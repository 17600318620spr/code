#include <stdio.h>

int main(int argc, const char *argv[])
{
	int mat[3][3]={{23, 4, 6}, {44, 30, 8}, {57, 80, 11}};
	int (*p)[3];
	p=mat;

	printf("mat[1][2]=%d\n", mat[1][2]);
	printf("%d\n", *(*(p+1)+2));
	puts("");
	printf("p[0][1]=%d\n", p[0][1]);
	printf("*(p[0]+1)=%d\n", *(p[0]+1));
	printf("p[2][0]=%d\n", p[2][0]);

	return 0;
}
