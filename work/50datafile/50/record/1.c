#include <stdio.h>

int main()
{
	FILE *fpr, *fpw;
	char buf[94100];

//	fpr=fopen("tt100.ts", "rb");
//	fpw=fopen("tt15.ts", "ab");

	fpr=fopen("test0.ts", "rb");
	fpw=fopen("tt500.ts", "ab");

	fread(buf, 1, sizeof(buf), fpr);
	fwrite(buf, 1, sizeof(buf), fpw);

	fclose(fpr);
	fclose(fpw);
	
	return 0;
}
