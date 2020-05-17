#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*return 1 : little-endian, return 0:big-endian*/
int checkCPUendian()
{
union{
	unsigned int a;
	unsigned char b;
}c;
	c.a = 1;
	return (c.b == 1);
}

int main()
{
	printf("return=%d\n", checkCPUendian());
	FILE *fp = fopen("tt10.ts", "rb");
	if(!fp) 
		return -1; 
	printf("file open success\n");
	fseek(fp, 0L, SEEK_END);  
	int size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	char *buffer = calloc(1, (size * sizeof(char)));

	int num = fread(buffer, 1, size, fp);
	int i = 0;
	int ts_len = 0;
	int ts_pid = 0;
	int pack_num = 0;

	char info[1024] = {0};

	FILE *fpw = fopen("pid.log", "ab");

	for(i; i < num; i++)
	{
		memset(info, 0, sizeof(info));
		if(buffer[i] == 0x47 && buffer[i+188] == 0x47)
		{
			ts_len = 188;
			ts_pid = ((buffer[i+1] & 0x1f)<<8) + buffer[i+2];
			sprintf(info, "--------------ts_pid=%x, ts_len=%d\n", ts_pid, ts_len);
			pack_num++;
		}
		
		if(buffer[i] == 0x47 && buffer[i+204] == 0x47)
		{
			ts_len = 204;
			ts_pid = ((buffer[i+1] & 0x1f)<<8) + buffer[i+2];
			sprintf(info, "?????????????ts_pid=%x, ts_len=%d\n", ts_pid, ts_len);
			pack_num++;
		}
		
		if(num-i<188)
		{
			if(buffer[i] == 0x47)
			{
				ts_len = 188;
				ts_pid = ((buffer[i+1] & 0x1f)<<8) + buffer[i+2];
				sprintf(info, ">>>>>>>>>>>>>>>>ts_pid=%x, ts_len=%d or 204\n", ts_pid, ts_len);
				pack_num++;
				puts("+++++++++++++++");
				break;
			}
		}

		fwrite(info, strlen(info), 1, fpw); // !!!
	}

	fclose(fpw);
	printf("file size=%d, %d, pack_num=%d ts_len=%d\n", num, strlen(buffer), pack_num, ts_len);

	free(buffer);
	fclose(fp);
	return 0;
}
