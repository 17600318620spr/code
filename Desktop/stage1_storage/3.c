#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
struct a{
	char p;
	int a;
};

struct a * func(){
	char buf[123]="hello world!";
	
//	time_t t = time(NULL);
//	printf("%s\n",ctime(&t));
//	char *p = ctime(&t);
	char *b=(char *)malloc(123);
	strcpy(b,"helloworld!");
	free(b);

	strcpy(b,"444444444444444rld!");
	return b;
}

int main(int argc, const char *argv[])
{
	char *p=func();
	printf("%s\n",p);
//	printf("%s\n",func());
	return 0;
}
