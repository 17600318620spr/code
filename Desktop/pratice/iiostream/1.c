#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "1.h"

int main(int argc, const char *argv[])
{
//	struct iio_buffer *rxbuf=NULL;
	struct iio_buffer *txbuf;

//	rxbuf->userdata=NULL;
//	txbuf->userdata=NULL;
//	txbuf->userdata=malloc(sizeof(int));

//	printf("%p %x %d\n", rxbuf->userdata, rxbuf->userdata, rxbuf->userdata);
//	printf("%p %x %d\n", txbuf->userdata, txbuf->userdata, txbuf->userdata);
puts("111111111111111111\n");
//	printf("%d %p\n", rxbuf->userdata, rxbuf->userdata);
	printf("%d %p\n", txbuf->userdata, txbuf->userdata);
puts("222222222222222222\n");
//	printf("%p\n", txbuf->dev);
//	printf("%p\n", txbuf->dev++); //core dumped!!!
	printf("%s\n", txbuf->buffer); //core dumped!!!

	return 0;
}
