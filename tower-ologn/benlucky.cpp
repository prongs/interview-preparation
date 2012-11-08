#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int T,p1,p2,alpha,beta,n,k;
int nums[10000000+10];
int a[10000000+10];
int b[10000000+10];
int main(int argc, char const *argv[])
{
	cin>>T;
	while(T--)
	{
		cin>>p1>>p2>>alpha>>beta>>n>>k;
		nums[0]=p1;nums[1]=p2;
		for (int i = 2; i < k; ++i)
		{
			nums[i]=alpha*nums[i-1]+beta*nums[i-2];
			nums[i]%=n;
			nums[i]=(nums[i]<0)?nums[i]+n:nums[i];
			// cout<<nums[i]<<" ";
		}		
		// cout<<endl;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		a[0]=1;b[0]=1;
		for (int i = 1; i < k; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if(nums[j]<nums[i])
				{
					a[i]=MAX(a[i],b[j]+1);
				}
				else if(nums[j]>nums[i])
				{
					b[i]=MAX(b[i],a[j]+1);
				}
				else
				{
					b[i]=MAX(b[i],b[j]);
					a[i]=MAX(a[i],a[j]);
				}

			}
			// cout<<a[i]<<", "<<b[i]<<endl;
		}
		int max=0;
		for (int i = 1; i < k; ++i)
		{
			max=MAX(max,MAX(a[i],b[i]));
		}
		cout<<max<<endl;
	}
	return 0;
}