#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a[3][2]={{1, 6}, {9, 12}, {61, 12}};
	int *p, i, n;

	n=sizeof(a)/sizeof(int);
	printf("n=%d\n", n);

	//a[1]++;
	printf("%d\n", sizeof(a[1]));

	p=a[0];//&a[0][0];
	printf("%p %p\n", p, p+1);
	printf("%p %p\n", a, a+1);

	for(i=0; i<n; i++)
	{
		printf("%d ", *(p+i));
	}
	puts("");

	return 0;
}
