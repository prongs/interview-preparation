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
#define pb push_back
//more defines


using namespace std;
class SurroundingGameEasy
{
public:
	int score (vector<string>cost,vector<string>benifit,vector<string>stone);
};

int SurroundingGameEasy::score (vector<string>cost,vector<string>benifit,vector<string>stone)
{
	int score = 0;
	for (int i = 0; i < cost.size(); ++i)
	{
		for (int j = 0; j < cost[0].size(); ++j)
		{
			if(stone[i][j]=='o')
			{
				score=score+((benifit[i][j]-'0')-(cost[i][j]-'0'));
			}
			else
			{
				bool left,right,up,down;
				left=right=up=down=true;
				if(i>0)
					up=(stone[i-1][j]=='o');
				if(i<stone.size()-1)
					down=(stone[i+1][j]=='o');
				if(j>0)
					left=(stone[i][j-1]=='o');
				if(j<stone[0].size()-1)
					right=(stone[i][j+1]=='o');
				if(left&&up&&down&&right)
					score+=(benifit[i][j]-'0');
			}
		}
	}
	return score;
}


int main(int argc, char const *argv[])
{
	vector<string> cost,benifit,stone;
	cost.pb("4362");cost.pb("4321");
	benifit.pb("5329");benifit.pb("5489");
	stone.pb("...o");stone.pb("..o.");
	SurroundingGameEasy s;
	cout<<s.score(cost,benifit,stone);
		
}
