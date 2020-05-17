#include <stdio.h>
//#include <stdbool.h>

int main(int argc, const char *argv[])
{
//	_Bool a;
	bool a;	

	a=true;
	a=false;
	a=-1;

	if(a)
	{
		printf("true %d\n", a);
	}
	else
	{
		printf("false %d\n", a);
	}
	
	return 0;
}
