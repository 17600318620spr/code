#include <stdio.h>

int main(int argc, const char *argv[])
{
//	char buf[240000];
//	char buf[5300];
	char buf[7500];
	FILE *fpr, *fpw;

	fpr=fopen("data1.txt", "rb");
	fpw=fopen("dt1.txt", "wb");

	fread(buf, 1, sizeof(buf), fpr);
	fwrite(buf, 1, sizeof(buf), fpw);
	
	fclose(fpr);
	fclose(fpw);
	return 0;
}
