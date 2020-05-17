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
				printf("Upper:%c\n", ch);
			}
			if(islower(ch))
			{
				printf("Lower:%c\n", ch);
			}
		}
		
		if(isdigit(ch))
		{
			printf("Digit:%d\n", ch-'0');
			printf("Digit:%c\n", ch);
		}

		putchar(ch);
	}
	
	return 0;
}
