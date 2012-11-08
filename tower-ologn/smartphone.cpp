#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)

#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

int T,perms[9];
map<int,int> edgeMap,freqMap;
void setEdgeMap(int from,int to,int value)
{
	edgeMap[1<<from|1<<to]=1<<value;
}
int getEdgeMap(int from, int to)
{
	return edgeMap[1<<from|1<<to];
}
void combineEdgeMap(int from,int mid,int to)
{
	edgeMap[1<<from|1<<to]=edgeMap[1<<from|1<<mid]|edgeMap[1<<mid|1<<to];
}
int main(int argc, char const *argv[])
{
	int t=0;
	setEdgeMap(1,2,t++);
	setEdgeMap(1,4,t++);
	setEdgeMap(1,5,t++);
	setEdgeMap(1,6,t++);
	setEdgeMap(1,8,t++);

	setEdgeMap(2,3,t++);
	setEdgeMap(2,4,t++);
	setEdgeMap(2,5,t++);
	setEdgeMap(2,6,t++);
	setEdgeMap(2,7,t++);
	setEdgeMap(2,9,t++);

	setEdgeMap(3,4,t++);
	setEdgeMap(3,5,t++);
	setEdgeMap(3,6,t++);
	setEdgeMap(3,8,t++);	

	setEdgeMap(4,5,t++);
	setEdgeMap(4,7,t++);
	setEdgeMap(4,8,t++);
	setEdgeMap(4,9,t++);	

	setEdgeMap(5,6,t++);
	setEdgeMap(5,7,t++);
	setEdgeMap(5,8,t++);
	setEdgeMap(5,9,t++);		

	setEdgeMap(6,7,t++);
	setEdgeMap(6,8,t++);
	setEdgeMap(6,9,t++);		

	setEdgeMap(7,8,t++);

	setEdgeMap(8,9,t++);


	combineEdgeMap(1,2,3);
	combineEdgeMap(1,4,7);
	combineEdgeMap(1,5,9);
	combineEdgeMap(2,5,8);
	combineEdgeMap(3,5,7);
	combineEdgeMap(3,6,9);
	combineEdgeMap(4,5,6);
	combineEdgeMap(7,8,9);


	int myints[]={1,2,3,4,5,6,7,8,9};
	do{
		int num=0;
		for (int i = 0; i < 8; ++i)
		{
			num|=getEdgeMap(myints[i],myints[i+1]);
		}
		freqMap[num]++;
	}while(next_permutation(myints, myints+9));	
	cin>>T;
	while(T--)
	{
		for (int i = 0; i < 9; ++i)
		{
			cin>>perms[i];
		}
		int num=0;
		for (int i = 0; i < 8; ++i)
		{
			num|=getEdgeMap(perms[i],perms[i+1]);
		}
		cout<<(freqMap[num]-1)<<endl;
	}
	return 0;
}