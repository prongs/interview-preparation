#define s(n) scanf("%d", &n)
#define p(n) printf("%d\n", n)
#define sf(n) scanf("%f", &n)
#define pf(n) printf("%f\n", n)
#define sc(n) scanf("%c", &n)
#define pc(n) printf("%c\n", n)
#define ss(n) scanf("%s", n)
#define ps(n) printf("%s\n", n)
#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)
/*more #defines*/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
/*more #includes*/

using namespace std;

struct prob
{
	double p1; /*prob that strangelandian wins*/
	double p2; /*prlb that non strangelandian wins*/
};

int T; /*number of test cases*/
int N,M,P;/*integers to be scanned every loop*/
int loc[10000];

struct prob calc_prob(int start, int size)
{
	struct prob ans;
	ans.p1=0;ans.p2=0;
	if(size==1)
	{
		if(binary_search(loc, loc+M,start))
			ans.p1=1.0;
		else
			ans.p2=1.0;
		// printf("start=%d size=%d,ans.p1=%f ans.p2=%f\n",start,size,ans.p1,ans.p2);
		return ans;
	}
	struct prob left,right;
	left=calc_prob(start,size/2);
	right=calc_prob(start+size/2, size/2);
	ans.p1=left.p1*right.p1+(left.p1*right.p2+left.p2*right.p1)*P/100.0;
	ans.p2=left.p2*right.p2+(left.p1*right.p2+left.p2*right.p1)*(1-P/100.0);
	// printf("start=%d size=%d,ans.p1=%f ans.p2=%f\n",start,size,ans.p1,ans.p2);
	return ans;
}

int main(int argc, char const *argv[])
{
	/* code */
	s(T);
	while(T--)
	{
		s(N);s(M);s(P);
		for (int i = 0; i < M; ++i)
		{
			s(loc[i]);
			loc[i]--; //0-base
		}
		sort(loc, loc+M);
		struct prob p=calc_prob(0,N);
		pf(p.p1*100.0);
	}
	
	return 0;
}
