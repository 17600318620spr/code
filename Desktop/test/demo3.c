#include <stdio.h>
#include <string.h>

#define N 20

int main(int argc, const char *argv[])
{
	char arr[N]={0};
	int i, j, n, tmp;

	printf("input a string:");
	gets(arr);

	n=strlen(arr);
	i=0;
	j=n-1;

	while(i<j)
	{
		tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
		i++;
		j--;
	}

	puts(arr);

	return 0;
}
