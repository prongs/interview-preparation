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
struct Node
{
	bool terminal; 
	struct Node* left; struct Node* right;
	Node(){
		terminal=false;left=NULL;right=NULL;
	}
};

typedef struct Node Node;


class CuttingBitString
{
public:
	Node root;
	int getmin(string str);
	void insert5Powers();
	int findAns(string str);
	int findAll5Powers(string str);

	/* data */
};
int CuttingBitString::findAll5Powers(string str)
{
	if(str.compare("")==0)
		return 1;
	vector<string> list;
	int ways=0;
	Node* cur = &root;
	for (int i = 0; i < str.size()+1; ++i)
	{
		if(cur->terminal)
		{
			// cout<<"pushing "<<str.substr(i)<<endl;
			list.pb(str.substr(i));
		}
		if(str[i]=='0')
		{
			if(cur->left == NULL)
				break;
			cur = cur->left;
		}
		else
		{
			if(cur->right == NULL)
				break;
			cur = cur->right;
		}
	}
	for (int i = list.size()-1; i >= 0; --i)
	{
		// cout<<"listi= "<<list[i]<<endl;
		int k=(findAll5Powers(list[i]));
		if(k>=0)
		{
			// cout<<"inside k>=0 if"<<endl;
			return (list[i].compare("")==0)?k:(k+1);
		}
	}
	return -1;
}
void CuttingBitString::insert5Powers()
{
	string a[] = {"1", "101", "11001", "1111101", "1001110001", "110000110101", "11110100001001", "10011000100101101", "1011111010111100001", "111011100110101100101", "100101010000001011111001", "10111010010000111011011101", "1110100011010100101001010001", "1001000110000100111001110010101", "101101011110011000100000111101001", "11100011010111111010100100110001101", "10001110000110111100100110111111000001", "1011000110100010101111000010111011000101", "110111100000101101101011001110100111011001", "100010101100011100100011000001001000100111101", "10101101011110001110101111000101101011000110001", "1101100011010111001001101011011100010111011110101", "1000011110000110011110000011001001101110101011001001", "101010010110100000010110001111110000101001010111101101"};
	for (int i = 0; i < 24; ++i)
	{
		string s = a[i];
		Node* n = &root;
		for (int j = 0; j < s.size(); ++j)
		{
			if (s[j]=='0')
			{
				if(n->left == NULL)
					n->left = new Node();
				n = n->left;
			}
			else
			{
				if(n->right == NULL)
					n->right = new Node();
				n = n->right;
			}
		}
		n->terminal = true;
	}
	
}
int CuttingBitString::findAns(string str)
{	
	return findAll5Powers(str);
}
int CuttingBitString::getmin(string str)
{
	insert5Powers();
	return findAns(str);
}

int main(int argc, char const *argv[])
{
	CuttingBitString c;	
	int p = c.getmin("101101101");
	cout<<p<<endl;
}
