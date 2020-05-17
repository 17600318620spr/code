#include <stdio.h>
#include <string.h>

#define N 20

int main(int argc, const char *argv[])
{
//	char arr[]="welcome";
	char arr[N]={0};
	int i, n;

	printf("input a string:");
	gets(arr);

//	n=sizeof(arr)/sizeof(char);// n=20
	n=strlen(arr);
	printf("n=%d\n", n);

	for(i=n-1; i>=0; i--)
	{
//		printf("i=%d\n", i);
		putchar(arr[i]);
	}
	putchar('\n');

	return 0;
}
