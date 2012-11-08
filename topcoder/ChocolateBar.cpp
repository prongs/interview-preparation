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

#define pb push_back
using namespace std;

class ChocolateBar
{
public:
	int maxLength(string letters);

	/* data */
};

int ChocolateBar::maxLength(string letters)
{
	vector<int> nexts(letters.size(),letters.size());
	vector<int> max_lens(letters.size(),1);
	vector<int> charLoc(256,letters.size());
	for (int i = letters.size()-1; i >=0; --i)
	{
		char l = letters[i];
		nexts[i] = charLoc[l];
		charLoc[l] = i;
	}
	int am=0;
	for (int i = 0; i < letters.size(); ++i)
	{
		int m = nexts[i];
		// cout<<"i= "<<i<<", char= "<<letters[i]<<", m="<<m<<endl;
		for (int j = i; j < letters.size(); ++j)
		{
			m = min(m,nexts[j]);
			// cout<<"\t"<<"nexts[j] = "<<nexts[j]<<" and new m = "<<m<<endl;
			if(j>=m)
				break;
		}
		// cout<<"i= "<<i<<", char= "<<letters[i]<<", m="<<m<<endl;
		am = max(am,m-i);
	}
	return am;
}

int main(int argc, char const *argv[])
{
	ChocolateBar c;
	const char* inputs[]= {
		"srm",
		"dengklek",
		"haha",
		"www",
		"thisisansrmbeforetopcoderopenfinals"
	};
	vector<string> v(inputs,inputs+5);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<c.maxLength(v[i])<<endl;
	}
	return 0;
}
