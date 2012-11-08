// Ideone_Language_Id:1
/* Don't remove the first line! */
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
/*more #includes. Don't write "using namespace std" here*/

using namespace std;
class Time
{

	public:
		string whatTime(int seconds);

};

string Time::whatTime(int seconds)
{
	int s=seconds%60;
	int minutes=seconds/60;
	int m=minutes%60;
	int h=minutes/60;
	stringstream ss;
	ss<<h<<":"<<m<<":"<<s;
	return ss.str();
}