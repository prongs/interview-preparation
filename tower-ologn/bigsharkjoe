#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int T,N,Q;
short nums[100000];

int scan_int()
{
	int t=0;
	char c;
	c=getchar_unlocked();
	while(c<'0' || c>'9')
		c=getchar_unlocked();
	while(c>='0' && c<='9')
	{
		t=(t<<3)+(t<<1)+c-'0';
		c=getchar_unlocked();
	}
	return(t);
}

short scan_short()
{
	short t=0;
	char c;
	c=getchar_unlocked();
	while(c<'0' || c>'9')
		c=getchar_unlocked();
	while(c>='0' && c<='9')
	{
		t=(t<<3)+(t<<1)+c-'0';
		c=getchar_unlocked();
	}
	return(t);
}

char scan_char()
{
	char t=0;
	char c;
	c=getchar_unlocked();
	while(c<'0' || c>'9')
		c=getchar_unlocked();
	while(c>='0' && c<='9')
	{
		t=(t<<3)+(t<<1)+c-'0';
		c=getchar_unlocked();
	}
	return(t);
}


int main(int argc, char const *argv[])
{
	T=scan_int();
	while(T--)
	{
		N=scan_int();
		for (int i = 0; i < N; ++i)
		{
			nums[i]=scan_char();
		}
		Q=scan_int();
		for (int i = 0; i < Q; ++i)
		{
			int t,i,j;
			t=scan_int();
			i=scan_int();
			j=scan_int();
			if(t==0)
			{
				int sum=0;
				for (int k = i-1; k < j; ++k)
				{
					sum+=nums[k];
				}
				printf("%d\n",sum);
			}
			else
			{
				for (int k = i-1; k < j; ++k)
				{
					nums[k]=MAX(nums[k]-20,nums[k]-nums[k]/3);
				}
			}
		}
	}
	return 0;
}