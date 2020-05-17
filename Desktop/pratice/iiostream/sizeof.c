#include <stdio.h>
#include <stdbool.h>

struct iio_content_pdata
{
	void *addrinfo;
	int *lock;
	bool msg_trync_supported;
};

int main(int argc, const char *argv[])
{
//	struct iio_content_pdata *pdata;
	struct iio_content_pdata *pdata=NULL;

	printf("iio_content_pdata=%d\n", sizeof(struct iio_content_pdata));
	printf("pdata=%d\n", sizeof(pdata));
	printf("*pdata=%d\n", sizeof(*pdata));

//	printf("%p\n", pdata->addrinfo);//core dumped!!!
//	printf("%d\n", pdata->addrinfo);//core dumped!!!

	return 0;
}
