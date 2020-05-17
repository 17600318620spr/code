#include <stdio.h>

int main(int argc, const char *argv[])
{
	char fruit[][20]={"banana", "apple", "pear", "orange"};
	int i, n;

	n=sizeof(fruit)/sizeof(fruit[0]);

	for(i=0; i<n; i++)
	{
//		printf("%s\n", fruit[i]);
		puts(fruit[i]);
	}

	return 0;
}
