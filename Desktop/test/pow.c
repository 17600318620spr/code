#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	int n=100;
	int a, b ,c;

	while(n<=999)
	{
		a=n/100;
		b=n/10%10;
		c=n%10;

		if(pow(a, 3)+pow(b, 3)+pow(c, 3)==n)
		{
			printf("%d\n", n);
		}
		n++;
	}
	
	return 0;
}
