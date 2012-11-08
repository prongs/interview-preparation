#define s(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)
#include <iostream>
#include <string.h>
using namespace std;
#define L (~(1<<30|1<<31))



int T,N,C,Q,A,B,D,X[500000],M[1000], Y[500000];


int main(int argc, char const *argv[])
{
	s(T);
	while(T--)
	{
		scanf("%d %d %d %d %d %d", &N, &C, &Q,&A, &B, &D);
		int n=MIN(N, 10000);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", X+i);
		}
		for (int i = n; i < N; ++i)
		{
			X[i]=(X[i-1]*A+X[i-2]*B+D)&L;
		}
		for (int i = 0; i < Q; ++i)
		{
			cin>>M[i];
		}
		for (int i = 0; i < N; ++i)
		{
			int min=X[i];
			int max=X[i];
			Y[i]=N-1;
			for (int j = i+1; j < N; ++j)
			{
				min=MIN(min, X[j]);
				max=MAX(max, X[j]);
				if (max-min>C)
				{
					Y[i]=j-1;
					break;
				}
			}
		}
		int cand[N+1];
		for (int k = 1; k <= N; ++k)
		{
			cand[k]=0;
			for (int i = 0; i < N-k+1; ++i)
			{
				if(Y[i]>=i+k-1)
					cand[k]++;
			}
		}
		for (int i = 0; i < Q; ++i)
		{
			int m=M[i];
			int max=-1;
			int k_best=0;
			for (int k = 1; k <= N; ++k)
			{
				if(cand[k]<=m&&max<cand[k])
				{
					max=cand[k];
					k_best=k;
				}
			}
			cout<<k_best<<" "<<max<<endl;
		}

	}
	return 0;
}