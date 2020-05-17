#include <stdio.h>

int main(int argc, const char *argv[])
{
	char arr1[]={'a', 'b', 'c'};
	char arr2[6]={'d', 'e', 'f'};

//	printf("arr1:%s %p\n", arr1, arr1);
	printf("arr1:%s %p\n", arr1, &arr1[2]);
	printf("arr2:%s %p\n", arr2, arr2);
	
	return 0;
}
