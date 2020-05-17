#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int ret, count=0;
	char src_buf[40960];
	char dst_buf[10240];
	FILE *fpr;
	FILE *fpw;
	int pid;
	char *p;

	fpr=fopen("test1.ts", "rb");
	while(!feof(fpr))
	{
//		int i=0;
//		ret=fread(buf, 1, sizeof(buf), fpr);
//		p=buf;
//printf(">>>>>>>>ret=%d sizeof(buf)=%d sizeof(p+188)=%d\n", ret, sizeof(buf), sizeof(p+188));
//		while((p+188) < buf)
		while(ret=fread(src_buf, 1, sizeof(src_buf), fpr))
		{
			count+=ret;
			p=src_buf;
			if(0x47==p[0] && p[188]==0x47)
			{
//				fseek(fpr, (1-188), SEEK_CUR);
				pid=(p[1]&0x1f)<<8|p[2];
				if(pid==768)
				{
					fpw=fopen("test1_bak.ts", "ab");
printf("+++++++++p[0]=%x p[1]=%x p[2]=%x p[3]=%x p[4]=%x pid=%x\n", p[0], p[1], p[2], p[3], p[4], pid);
					fwrite(src_buf, 1, 188, fpw);
				}
//				p+=188;
printf("*********p[0]=%x p[1]=%x p[2]=%x p[3]=%x p[4]=%x p[5]=%x pid=%x\n", p[0], p[1], p[2], p[3], p[4], p[5], pid);
			}
			p++;
//printf("88888888p[0]=%x p[1]=%x p[2]=%x p[3]=%x p[4]=%x p[5]=%x pid=%x\n", p[0], p[1], p[2], p[3], p[4], p[5], pid);
		}
		count=count/188;
		printf("count=%d\n", count);
	}
	fclose(fpw);
	fclose(fpr);
	return 0;
}

