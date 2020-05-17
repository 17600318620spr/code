/*
 * 原文链接：https://blog.csdn.net/qq_34071268/article/details/78743564
 */
#include <stdio.h>
#include <stdlib.h>

char right, left, temp; 	//right表示第八位，left表示高八位
int size_right, size_left, size_temp;
short int number, size_number;
short int number_two, number_three; //int 是四个字节 short int 是两个字节
int main()
{
    number = 32343; 		//65536个数范围是 -32768-32767
    size_number = sizeof(number);
    size_right = sizeof(right);
    size_left = sizeof(left);
    size_temp = sizeof(temp);
    printf("size_number=%d个字节\n", size_number);
    printf("size_left=%d个字节\n", size_left);
    printf("size_right=%d个字节\n", size_right);
    printf("size_temp=%d个字节\n\n", size_temp);

    printf("number=%d\n", number);
    right = number&0XFF; //低八位
    left = number>>8; 	 //高八位
    printf("right = %d\n", right);
    printf("left  = %d\n", left);
    printf("number_two=%d\n", left*256+right);
    //前取高八位，在取低八位
    left=(number>>8)&0XFF; //先取高八位
    right=number&0XFF;     //再取第八位
    printf("number_two=%d\n", left*256+right);
    //现在要把高八位和第八位合并
    number_three=left;
    number_three<<=8;
    number_three|=right;
    printf("number_three=%d\n", number_three);
    return 0;
}
