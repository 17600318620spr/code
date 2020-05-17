#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "sweep.h"
char buff[5] = {0};
char *p = buff;
int main()
{
	int t, n;
	float t2;
	int k = 0;
	K = B/T;
	
	if((fd=fopen("./data.txt", "a+")) < 0)
	{
	    printf("Failed to open data.txt !\n");
	    exit(1);
	}

	for(t=-3000000; t<3000000; t++)
	{
	    t2 = (float)t/6000000;

	    ((int16_t*)p)[0] = (short)(cos(PI*K*t2*t2)*1024)<<4;
	    ((int16_t*)p)[1] = (short)(sin(PI*K*t2*t2)*1024)<<4;
	    fwrite(buff, 1, 4, fd);
	    
	}
	for(t=3000000; t>-3000000; t--)
	{
	    t2 = (float)t/6000000;
	    ((int16_t*)p)[0] = (short)(cos(PI*K*t2*t2)*1024)<<4;
	    ((int16_t*)p)[1] = (short)(sin(PI*K*t2*t2)*1024)<<4;
	    fwrite(buff, 1, 4, fd);
    
	}
	fclose(fd);

    return 0;
}

