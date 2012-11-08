#define s(n) scanf("%d", &n)
#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)
#include <iostream>
#include <string.h>

int T,N,X,nums[100],min, sum;
int main(int argc, char const *argv[])
{
	s(T);
	while(T--)
	{
		s(N);s(X);
		min=500;sum=0;
		for (int i = 0; i < N; ++i)
		{
			s(nums[i]);
			min=MIN(min,nums[i]);
			sum+=nums[i];
		}
		// printf("sum:%d,min:%d,X:%d,N:%d\n",sum,min,X,N);
		int mod=sum%X;
		if(mod>=min)
			printf("-1\n");
		else
		{
			int d=sum/X;
			printf("%d\n",d);
		}
	}
	return 0;
}