#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int ret=0, size=0, cc_count=0, addr=0, ccnt=0;
	char src_buf[420];
	char dst_buf[420];
	char cc_error[32]={0};
	FILE *fpr;
	FILE *fpw;
	FILE *fpcc;
	int pid;
	char *p;

	if(argc<4)
	{
		printf("Usage:%s <src_tsfile> <dst_tsfile> pid\n", argv[0],argv[1],argv[2],argv[3]);
		return -1;
	}

	fpr=fopen(argv[1], "rb");
	fpw=fopen(argv[2], "ab");
//	fpcc=fopen("cc.log", "ab");
	while(!feof(fpr))
	{
		ret=fread(src_buf+size, 1, sizeof(src_buf)-size, fpr);
		size+=ret;
		p=src_buf;
		while(p+188 < src_buf+size)
		{
			if((p[0]==0x47) && (p[188]==0x47))
			{
//				fseek(fpr, (1-188), SEEK_CUR);
				pid=(p[1]&0x1f)<<8|p[2];
				cc_count=p[3]&0xf;
//printf("*****p[0]=%x p[1]=%x p[2]=%x p[3]=%x p[4]=%x p[5]=%x p[188]=%x p[376]=%x pid=%x pid=%d cc_count=%x\n", \
		p[0], p[1], p[2], p[3], p[4], p[5], p[188], p[376], pid, pid, cc_count);
				if(pid==atoi(argv[3]))
				{
					if(cc_count==0)
					{
						if((ccnt-cc_count)!=15)
							printf("ERROR!!!\nERROR!!!\n");
					}
					else
					{
						if((cc_count-ccnt)!=1)
							printf("ERROR!!!\nERROR!!!\n");
					}
					printf("cc=%x addr=%x\t%d\n", cc_count, addr, addr);
					ccnt=cc_count;
//					sprintf(cc_error, "cc=%x addr=%x\t%d\n", cc_count, addr, addr);
//					fwrite(cc_error, strlen(cc_error), 1, fpcc);
					fwrite(p, 1, 188, fpw);
					p+=188;
					addr+=188;
				}
				else
				{
//puts("111111111111111111");
					p+=188;
					addr+=188;
				}
			}
			else
			{
				p++;
				addr+=1;
			}
		}
		size=src_buf+size-p;
		memcpy(src_buf, p, size);
	}
	fclose(fpw);
	fclose(fpr);
//	fclose(fpcc);
	return 0;
}

