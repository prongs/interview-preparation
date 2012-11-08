#define s(n) scanf("%d", &n)
#include <iostream>
using namespace std;
int T,N,p;
#define L (1000000007)
int pow(int a, int b)
{
	if(b==0)
		return 1;
	else if(b==1)
		return a;
	long x=pow(a,b/2);
	long y=pow(a,b%2);
	long r=(x*x)%L;
	r=(r*y)%L;
	return (int)r;
}

int main(int argc, char const *argv[])
{;
	s(T);
	for (int i = 0; i < T; ++i)
		{
			s(N);
			p=pow(3,N);
			p=(N%2==0)?p+3:p-3;
			printf("%d\n",p);
		}	
	return 0;
}