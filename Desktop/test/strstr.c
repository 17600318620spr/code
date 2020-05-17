#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char s[]="how are you";
	char subs[]="are";

	printf("%d\n", strstr(s, subs)-s);
	
	return 0;
}
