int Q(int n)//递归的方法求累加,Q1=1;Q2=Q1+2;.....n为累加次数
{
	if(n<1)
		printf("错误！");
		return 0;
	if(n==1)
		return 1;
	if(n>1)
		return (Q(n-1)+n);
}

//全局函数的方法，利用静zd态量保存过程值
int Sum=0;
int Nums=100;//累加次数
for(int i=1;i<=Nums;i++)
{
	Sum+=i;
}
