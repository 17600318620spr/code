#include <stdio.h>

int main(int argc, const char *argv[])
{
//	char a[5]={3,4,5,6};
//	a[1]=32;
	char a[5];
	a[0]=3;
	a[1]=4;
	a[4]=10;
//	a[5]={3,4,0,0,10};

	printf("%d", a[4]);
	
	return 0;
}
