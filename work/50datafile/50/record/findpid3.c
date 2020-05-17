#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int ret, size=0, flag=0;
	char buf[188];
	FILE *fpr;
	FILE *fpw;
	int pid;
	char *p;

	fpr=fopen("test001.ts", "rb");
	while(!feof(fpr))
	{
		ret=fread(buf+size, 1, sizeof(buf)-size, fpr);
		size+=ret;
		p=buf;
printf(">>>>>>>>>>>>>>>>>ret=%d\n", ret);
//		while(p+188<buf+size)
		while(1)
		{
//printf("11111111111p[0]=%d p[1]=%d p[2]=%d\n", p[0], p[1], p[2]);
//			if(p[0]==0x47 && p[188]==0x47)
			if(p[0]==0x47)
			{
				pid=(p[1]&0x1f)<<8|p[2];
printf("22222222222p[0]=%d p[1]=%d p[2]=%d pid=%d\n", p[0], p[1], p[2], pid);
/*				if(pid==768)
				{
					flag=(p[3]>>4)&0x03;
					switch(flag)
					{
					case 2:
						p+=188;
						continue;
					fpw=fopen("test001_bak.ts", "ab");
printf("##################ret=%d\n", ret);
					fwrite(buf, 1, sizeof(buf), fpw);
					}
				}  */
			}
			p+=188;
		}
		fclose(fpw);
		fclose(fpr);
		return 0;
	}
}
