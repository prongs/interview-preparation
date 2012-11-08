#define s(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)
#include <iostream>
#include <string.h>

int T,len;
char A[20001], B[20001],out[20001];
int digA[10], digB[10];
int cur=0;
void addChar(char c, int n)
{
	for (int i = 0; i < n; ++i)
	{
		out[cur++]=c;
	}
}
void showDigits()
{
	printf("digA: [0:%d, 1:%d, 2:%d, 3:%d, 4:%d, 5:%d, 6:%d, 7:%d, 8:%d, 9:%d]\n", digA[0], digA[1], digA[2], digA[3], digA[4], digA[5], digA[6], digA[7], digA[8], digA[9]);
	printf("digB: [0:%d, 1:%d, 2:%d, 3:%d, 4:%d, 5:%d, 6:%d, 7:%d, 8:%d, 9:%d]\n", digB[0], digB[1], digB[2], digB[3], digB[4], digB[5], digB[6], digB[7], digB[8], digB[9]);
	printf("\n");
}
void proc(int* from, int fi, int* to, int ti)
{
	int m=MIN(from[fi], to[ti]);
	to[ti]-=m;
	addChar(ti+'0', m);
	from[fi]-=m;

}
void procBA(int fi, int ti)
{
	proc(digB, fi, digA, ti);
}
void procAB(int fi, int ti)
{
	proc(digA, fi, digB, ti);
}
int main()
{
	s(T);
	while(T--)
	{
		ss(A);
		ss(B);
		memset(out, 0, sizeof(out));
		memset(digA, 0, sizeof(digA));
		memset(digB, 0, sizeof(digB));
		cur=0;
		len=strlen(A);
		for (int i = 0; i < len; ++i)
		{
			digA[A[i]-'0']++;
			digB[B[i]-'0']++;
		}
		procBA(6, 7);
		procBA(5, 7);
		procBA(3, 7);
		procBA(2, 7);
		procBA(1, 7);
		procBA(0, 7);
		procBA(4, 7);

		procAB(7, 7);
		procAB(6, 7);
		procAB(5, 7);
		procAB(3, 7);
		procAB(2, 7);
		procAB(1, 7);
		procAB(0, 7);
		procAB(4, 7);

		procBA(3, 4);
		procBA(2, 4);
		procBA(1, 4);
		procBA(0, 4);

		procAB(4, 4);
		procAB(3, 4);
		procAB(2, 4);
		procAB(1, 4);
		procAB(0, 4);

		printf("%s\n",out);
	}
}
