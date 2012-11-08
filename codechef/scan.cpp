#include <stdio.h>

void scan(int* i)
{
	int t=0;
	char c;
	bool negative=false;
	c=getchar_unlocked();
	while(c<'0'&&c>'9')
	{
		if(c=='-')
			negative=true;
		c=getchar_unlocked();
	}
	while(c>'0'&&c<'9')
	{
		t=(t<<3)+(t<<1)+c-'0';
		c=getchar_unlocked();
	}
	if(negative)
		t=~(t-1); //negative
	*i=t;
}

int main(int argc, char const *argv[])
{
	int i;
	scan(&i);
	return 0;
}
