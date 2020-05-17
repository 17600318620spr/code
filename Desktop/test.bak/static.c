#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i=1;

	while(i<5)
	{
//		int a=0;
		static int a=5;		
		a++;
		printf("a=%d\n", a);
		i++;
	}
	
	return 0;
}
