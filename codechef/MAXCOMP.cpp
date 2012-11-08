#define s(n) scanf("%d", &n)
#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)
#include <iostream>
#include <string.h>
using namespace std;
struct order
{
	int S;int E;int C;
};

int T,N;
order orders[4000];
int maxlist[49]; //I'll only use 1 to 48 indices.
int maxtillnow;
void merge(order* left, order* right, int n1, int n2, order* dst)
{	
	int i=0,j=0, k=0;
	while(i<n1 &&j<n2)
	{
		if(left[i].E<right[j].E)
		{
			dst[k++]=left[i++];
		}
		else
		{
			dst[k++]=right[j++];
		}
	}
	while(i<n1)
		dst[k++]=left[i++];
	while(j<n2)
		dst[k++]=right[j++];
}
void mergesort(order* src, int n, order* dst)
{
	if(n==1)
	{
		dst[0]=src[0];
		return;
	}
	int n1=n/2;
	int n2=n-n1;
	order left[n1];
	order right[n2];
	mergesort(src,n1,left);
	mergesort(src+n1, n2, right);
	merge(left,right,n1,n2,dst);
}

order* sortByEndTime(int n)
{
	order* src=orders;
	order* dst=orders+2000;
	mergesort(src, n,dst);
	return dst;
}


int main(int argc, char const *argv[])
{	
	s(T);
	while(T--)
	{
		s(N);
		for(int n=0;n<N;n++)
		{
			scanf("%d %d %d", &(orders+n)->S, &(orders+n)->E, &(orders+n)->C);			
		}		
		order* sorted=sortByEndTime(N);
/*		
		for (int i = 0; i < N; ++i)
		{
			printf("%d, %d, %d\n", sorted[i].S,sorted[i].E, sorted[i].C);
		}
*/		
		memset(maxlist, 0, sizeof(maxlist));
		maxtillnow=0;
		int lastE=0;
		for (int i = 0; i < N; ++i)
		{
			int E=sorted[i].E;
			int C=sorted[i].C;
			int S=sorted[i].S;
			for (int e = lastE; e < E; ++e)
			{
				maxlist[e]=maxlist[lastE];
			}
			maxlist[E]=MAX(maxlist[E], maxlist[S]+C);
			maxtillnow=MAX(maxtillnow, maxlist[E]);
			maxlist[E]=maxtillnow;
			lastE=E;
		}
		for (int e=lastE; e < 49; ++e)
		{
			maxlist[e]=maxlist[lastE];
		}
		printf("%d\n", maxlist[48]);
	}
	return 0;
}