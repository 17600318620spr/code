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

	for(n=0; n<3; n++)
	{
		if(n==0)
		{
			int k=0;
			if((fd0=fopen("./data1.txt", "a+")) < 0)
			{
	    		printf("Failed to open data1.txt !\n");
	    		exit(1);
			}
			for(t=-temp+step*n; t<-temp+step*(n+1); t++)
			{
	    		t2 = (float)t/Fs;
				k++;
	    		((int16_t*)p)[0] = (short)(cos(PI*K*t2*t2)*1024)<<4;
	    		((int16_t*)p)[1] = (short)(sin(PI*K*t2*t2)*1024)<<4;
	    		fwrite(buff, 1, 4, fd0);
			}
			fclose(fd0);
		}
		else if(n==1)
		{
			int k=0;
			if((fd1=fopen("./data2.txt", "a+"))<0)
			{
	    		printf("Failed to open data2.txt !\n");
	    		exit(1);
			}
			for(t=temp-step*(n-25+0); t>temp-step*(n-25+1); t--)
			{
	    		t2 = (float)t/Fs;
				k++;
	    		((int16_t*)p)[0] = (short)(cos(PI*K*t2*t2)*1024)<<4;
	    		((int16_t*)p)[1] = (short)(sin(PI*K*t2*t2)*1024)<<4;
	    		fwrite(buff, 1, 4, fd1);
			}
			fclose(fd1);
		}
		else if(n==2)
		{
			int k=0;
			if((fd2=fopen("./data3.txt", "a+"))<0)
			{
	    		printf("Failed to open data3.txt !\n");
	    		exit(1);
			}
			for(t=temp-step*(n-25+0); t>temp-step*(n-25+1); t--)
			{
	    		t2 = (float)t/Fs;
				k++;
	    		((int16_t*)p)[0] = (short)(cos(PI*K*t2*t2)*1024)<<4;
	    		((int16_t*)p)[1] = (short)(sin(PI*K*t2*t2)*1024)<<4;
	    		fwrite(buff, 1, 4, fd2);
			}
			fclose(fd2);
		}
		else
		{
			printf("Create Date Finished!");
		}
	}

    return 0;
}

