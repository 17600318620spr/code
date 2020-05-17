#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int *p;
	p=(int *)malloc(sizeof(int));
	if(NULL==p)
	{
		perror("malloc");
		exit(-1);
	}


	free(p);
	p=NULL;
	
	return 0;
	printf("%s\n", __func__);
}
