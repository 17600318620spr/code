#include <stdio.h>
/*
   非递归求：f(1) + f(2) + ... + f(m)
   其中 f(n) = n*(n+1)
   */
unsigned int sum_fn(unsigned int m)
{
	int n, sum=0;
	for(n=1; n<=m ;n++)
	{
		sum += n*(n+1);
	}
	return sum;
}
/*
   递归求：f(1) + f(2) + ... + f(m)
   其中 f(n) = n*(n+1)
   递归原理：
   当 m=1
   sum(m) = sum(1) = 1*(1+1) = 2
   当 m >= 2
   sum(m) = f(1) + f(2) + ...+ f(m-1) + f(m)
   = sum(m-1) + f(m)
   = sum(m-1) + m(m+1)
   */
unsigned int sum_fn_recursion(unsigned int m)
{
	if(m == 1)
		return m*(m+1);
	else
		return sum_fn_recursion(m-1) + m*(m+1);
}
int main(int argc, char *argv[])
{
	printf("%u %u\n",sum_fn(1000), sum_fn_recursion(1000));
	return 0;
}
