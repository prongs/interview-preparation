// Ideone_Language_Id:1
/* Don"t remove the first line! */
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <set>
#include <utility>
#include <stack>
#include <cmath>
#include <cassert>
//more includes
#define foreach(v,c) for(typeof((c).begin()) v=(c).begin();v!=(c).end();++v)
#define all(a) a.begin(),a.end()
#define in(a,b) ((b).find(a)!=(b).end())
#define pb push_back
#define fill(a,v) memset(a,v,sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define pb push_back
//more defines


using namespace std;
class FixedPointTheorem
{
public:
	double cycleRange (double R);
};

double FixedPointTheorem::cycleRange (double R)
{
	double x = 0.25;
	for (int i = 0; i <= 20000; ++i)
	{
		x = R * (1-x) * x;
	}
	double mn,mx;
	mn=mx=x;
	for (int i = 0; i < 999; ++i)
	{
		x=R*(1-x)*x;
		mn = (x>mn)?mn:x;
		mx=(x<mx)?mx:x;
	}
	return mx-mn;
}


int main(int argc, char const *argv[])
{

	/*main testing code*/
}

