#include <stdio.h>
#include <string.h>

#define N 36

int main(int argc, const char *argv[])
{
	char src[]="makeru";
	char dest[N];
	int i, n;

	i=0;
	n=strlen(src);
	while(i<=n)
	{
		dest[i]=src[i];
		i++;
	}

	puts(src);
	puts(dest);
	
	return 0;
}
