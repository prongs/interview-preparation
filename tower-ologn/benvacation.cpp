#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)

#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int T,X,Y,q,V,U,R;
vector<short> series;
vector<long long int> locations;

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


int get_next_V(int d)
{
	vector<int>::iterator up=upper_bound(locations.begin(), locations.end(),d);
	if(*(up-1)==d)
		return d;
	if(up!=locations.end())
	{
		return *up;
	}
	while(true)
	{
		int sz=series.size();
		int new_num=(X*series[sz-1]+Y*series[sz-2])%q;
		// cout<<"new number= "<<new_num<<endl;
		series.push_back(new_num);
		if(new_num==V)
		{
			locations.push_back(series.size()-1);
			if(series.size()-1>=d)
				return series.size()-1;
		}
	}
}

int main(int argc, char const *argv[])
{
	T=scan_int();
	while(T--)
	{
		X=scan_int();
		Y=scan_int();
		q=scan_int();
		V=scan_int();
		U=scan_int();
		R=scan_int();

		locations.clear();
		series.clear();
		locations.push_back(1);
		series.push_back(U);
		series.push_back(V);
		for (int i = 0; i < R; ++i)
		{
			int d;
			d=scan_int();
			// cout<<"d="<<d<<endl;
			cout<<get_next_V(d)-d<<endl;
		}
	}
	return 0;
}

