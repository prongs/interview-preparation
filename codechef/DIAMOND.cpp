#define s(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)

#include <iostream>
#include <string.h>

int T, N;
short V[2001];
float coeffs[2003*1001];
void preprocess()
{
	// fill(coeffs,0);
	memset(coeffs, 0, sizeof coeffs);
	int i=0;
	coeffs[i++]=1.0;
	coeffs[i++]=1/2.0;coeffs[i++]=1/2.0;
	coeffs[i++]=3/4.0;coeffs[i++]=2/4.0;coeffs[i++]=3/4.0;
	coeffs[i++]=5/8.0;coeffs[i++]=3/8.0;coeffs[i++]=3/8.0;coeffs[i++]=5/8.0;
	//coeffs[i++]=11/16.0;coeffs[i++]=8/16.0;coeffs[i++]=10/16.0;coeffs[i++]=8/16.0;coeffs[i++]=11/16.0;
	int j=4;
	int denom=1<<(j-1);
	for (; j < 2001; ++j)
	{		
		int startind=(j*(j-1))/2;
		int startind_n_minus_2=((j-2)*(j-3))/2;
		int a=startind,b=startind_n_minus_2;
		float aa,bb;
		aa=coeffs[a++]=coeffs[b]/4.0+0.5;
		bb=coeffs[a++]=(2.0*coeffs[b]+coeffs[b+1])/4.0;
		for (int k = 0; k < j-4; ++k)
		{
			coeffs[a++]=(coeffs[b]+2*coeffs[b+1]+coeffs[b+2])/4.0;
			b++;
		}
		coeffs[a++]=bb;
		coeffs[a++]=aa;		
		// printf("current coeffs: for j=%d: ",j);
		// for (int l = 0; l < j; ++l)
		// {
		// 	printf(" %.3f", coeffs[startind+l]);
		// }
		// printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	preprocess();
	s(T);
	while(T--)
	{
		s(N);
		int startind=(N*(N-1))/2;
		float t=0;
		int c=0;
		for (int i = 0; i < N; ++i)
		{
			s(c);
			t+=c*coeffs[startind+i];
		}				
		printf("%.3f\n",t);
	}
	return 0;
}
