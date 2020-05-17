#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char s1[]="abas$f$dsf";
	int ch;

	ch='$';

	//printf("%p %p\n", s1, strchr(s1, ch));
	//printf("%p %p\n", s1, strrchr(s1, ch));
	
	printf("%d\n", strchr(s1, ch)-s1);
	printf("%d\n", strrchr(s1, ch)-s1);

	return 0;
}
