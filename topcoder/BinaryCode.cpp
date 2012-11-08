#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class BinaryCode
{
public:
	vector<string> decode(string message);
	inline string decode_with_initial(char c, string message);

};

vector<string> BinaryCode::decode(string message)
{
	vector<string> res(2);
	res[0]=decode_with_initial('0',message);
	res[1]=decode_with_initial('1',message);
	return res;
}
inline string BinaryCode::decode_with_initial(char c, string message)
{
	int l=message.length();
	char result[l+1];
	result[l]=0;
	result[0]=c;
	result[1]=message[0]-(result[0]-'0');
	if(result[1]>'1'||result[1]<'0')
		return "NONE";
	for (int i = 1; i < l-1; ++i)
	{
		result[i+1]=message[i]-(result[i]-'0')-(result[i-1]-'0');
		if(result[i+1]>'1'||result[i+1]<'0')
			return "NONE";
	}
	result[l-1]=message[l-1]-(result[l-2]-'0');
	if(result[l-1]>'1'||result[l-1]<'0')
		return "NONE";
	return string(result);
}
