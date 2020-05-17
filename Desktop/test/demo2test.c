#include <stdio.h>

int main(int argc, const char *argv[])
{
	char arr[]="welcome";
	int i, n;

	n=sizeof(arr)/sizeof(char);

	for(i=n-1; i>=0; i--)
	{
		putchar(arr[i]);
//		printf("i=%d ", i);
	}
	puts("");
	
	return 0;
}
