#include <stdio.h>
#include <ctype.h>

int main(int argc, const char *argv[])
{
	int ch;
	
	while((ch=getchar())!=EOF)
	{
		if(isalpha(ch))
		{
			if(isupper(ch))
			{
				ch=tolower(ch);
			}
			else
			{
				ch=toupper(ch);
			}
			printf("%c\n", ch);
		}
	}
	
	return 0;
}
