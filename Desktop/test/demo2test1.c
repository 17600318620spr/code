#include <stdio.h>
#include <string.h>

#define N 20

int main(int argc, const char *argv[])
{
	//char arr[N];
	char arr[N]={0};
	int i, n;

	printf("input a string:");
	gets(arr);

	n=strlen(arr);

	for(i=n-1; i>=0; i--)
	{
		putchar(arr[i]);
	}
	puts("");
	
	return 0;
}
