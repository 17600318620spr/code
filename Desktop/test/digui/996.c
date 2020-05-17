#include<stdio.h>
#define Max 12345 

int main()
{
	int wei[Max],jinwei[Max];
	int i,j,n,k,top=1;

	wei[1]=1,jinwei[1]=1;

	printf("please input a number:\n");
	scanf("%d",&n);

	for(i=2;i<=n;i++)
	{
		for(j=1;j<=top;j++)
		{
			jinwei[j]=(wei[j]*i+jinwei[j-1])/10;
			wei[j]=(wei[j]*i+jinwei[j-1])%10;

			if(jinwei[top]>=1)
			{
				top++;
			}
		}
	}

	for(k=top;k>=1;k--)
	{
		printf("%d",wei[k]); 
	}

	getchar();getchar();
}
