/*
 * 原文链接：https://blog.csdn.net/yinchao163/article/details/53019218
 */
#include <stdio.h>
#include <stdlib.h>

void main()
{
	unsigned short a = 181, ta;	//16位无符号整数
	unsigned char b = 181, tb; 	//8位无符号整数
	short c = -75, tc;			//16位有符号整数
	char d = -75, td;			//8位有符号整数

	printf("无符号16位移位——逻辑移位举例\n");
	ta = a << 2;
	printf("移位前：%d\t左移2位后：%d\n", a, ta);
	ta = a >> 2;
	printf("移位前：%d\t右移2位后：%d\n\n", a, ta);


	printf("无符号8位移位——逻辑移位举例\n");
	tb = b << 2;
	printf("移位前：%d\t左移2位后：%d\n", b, tb);
	tb = b >> 2;
	printf("移位前：%d\t右移2位后：%d\n\n", b, tb);


	printf("有符号16位移位——算术移位举例\n");
	tc = c << 2;
	printf("移位前：%d\t左移2位后：%d\n", c, tc);
	tc = c >> 2;
	printf("移位前：%d\t右移2位后：%d\n\n", c, tc);


	printf("有符号8位移位——算术移位举例\n");
	td = d << 2;
	printf("移位前：%d\t左移2位后：%d\n", d, td);
	td = d >> 2;
	printf("移位前：%d\t右移2位后：%d\n\n", d, td);
	system("pause");

	return;
}
