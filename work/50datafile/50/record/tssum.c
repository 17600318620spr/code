#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{
#if 0
	int fdr;
	char buffer[1024];
	fdr=open("test0.ts", O_RDONLY);
	int readCount=read(fdr, buffer, 188*4);
	printf("readCount=%d\n", readCount);
	if(readCount==13)
	{
		while(1)
		{
			int fdw;
			fdw=open("test_bak.ts", O_CREAT|O_RDWR);
			write(fdw, buffer, 188*4-readCount);
		}
	}

#endif

	int ret, cc_count=0, size=0;
	char src_buf[240];
	char dst_buf[240];
	FILE *fpr;
	FILE *fpw;
	char *p;
	fpr=fopen("tt20.ts", "rb");
	fpw=fopen("tt20_bak.ts", "ab");

	while(!feof(fpr))
	{
		ret=fread(src_buf+size, 1, sizeof(src_buf)-size, fpr);
printf("1111111 ret=%d size=%d\n", ret, size);
		size+=ret;
printf("3333333 size=%d\n", size);
		p=src_buf;

//		while(p+188 < src_buf+size)
		while(p < src_buf+size)
		{
			if((0x47==p[0])&&(0x47==p[188]))
			{
//				fwrite(p[0], 1, 188, fpw);
				fwrite(p, 1, 188, fpw);
				p+=188;
			}
			else
			{
//				count+=1;
				fwrite(p, 1, 1, fpw);
				p++;
			}
		}
printf("4444444 size=%d\n", size);
		size=src_buf+size-p;
printf("5555555 size=%d\n", size);
		memcpy(src_buf,p,size);
//		fwrite(dst_buf, 1, size, fpw);
//		fwrite(dst_buf, 1, sizeof(dst_buf), fpw);
printf(">>>>>>>>>>size=%d sizeof(src_buf)=%d>>>>>>>>>\n", size, sizeof(src_buf));
	}
	fclose(fpw);
	fclose(fpr);
	return 0;
}
