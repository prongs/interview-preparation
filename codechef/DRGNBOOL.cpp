// Ideone_Language_Id: 1
#define s(n) scanf("%d", &n)
#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)
#include <iostream>
#include <string.h>
struct W
{
	int L; int C;
};
int T,N,M;
W Fs[100], Is[100];
int diff[100];
int maxdiff;
int main(int argc, char const *argv[])
{
	s(T);
	while(T--)
	{
		scanf("%d %d", &N,&M);
		memset(diff, 0, sizeof(diff));
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d", &(Is+i)->C, &(Is+i)->L);
			diff[Is[i].L-1]-=Is[i].C;
		}
		for (int i = 0; i < M; ++i)
		{
			scanf("%d %d", &(Fs+i)->C, &(Fs+i)->L);
			diff[Fs[i].L-1]+=Fs[i].C;
		}
		maxdiff=0;
		for (int i = 0; i < 100; ++i)
			maxdiff=(diff[i]<0)?maxdiff:maxdiff+diff[i];		
		printf("%d\n", maxdiff);

	}
	return 0;
}
