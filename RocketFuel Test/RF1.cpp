// Ideone_Language_Id:1
/* Don't remove the first line! */
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
#include <deque>
#include <cmath>
#include <cassert>
/*more #includes. Don't write "using namespace std" here*/

#ifdef __WIN32__
#define getchar_unlocked getchar
#endif
//Input-output macros
#define s(n) scan(&n)
#define p(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%f\n",n)
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c\n",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s\n",n)
// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v,c) for(typeof((c).begin()) v=(c).begin();v!=(c).end();++v)
#define all(a) a.begin(),a.end()
#define in(a,b) ((b).find(a)!=(b).end())
#define pb push_back
#define fill(a,v) memset(a,v,sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
// Some common useful functions
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define checkbit(n,b) ((n>>b)&1)
#define DREP(a) sort(all(a));a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())

/*Faster input functions*/
void scan(int* i){int t=0;char c;bool negative=false;c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')negative=true;c=getchar_unlocked();}while(c>='0'&&c<='9'){t=(t<<3)+(t<<1)+c-'0';c=getchar_unlocked();}if(negative)t=~(t-1);*i=t;}
void scan(long long int* i){long long int t=0;char c;bool negative=false;c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')negative=true;c=getchar_unlocked();}while(c>='0'&&c<='9'){t=(t<<3)+(t<<1)+c-'0';c=getchar_unlocked();}if(negative)t=~(t-1);*i=t;}
/*debug functions*/
#ifdef DEBUG
	#define debug(args...) {dbg,args;std::cout<<std::endl;}
#else
	#define debug(args...) // Just strip off all debug tokens
#endif
struct debugger{template<typename T> debugger& operator ,(const T& v){std::cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline std::ostream& operator<<(std::ostream& os,const std::pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::vector<T>& v){std::string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::deque<T>& v){std::string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::set<T>& v){std::string delim="[";for (typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline std::ostream&operator<<(std::ostream& os,const std::map<T1,T2>& v){std::string delim="[";for (typename std::map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}


using namespace std;

struct NumberOperation
{
	int push_operation_index; int pop_operation_index;
	NumberOperation()
	{
		push_operation_index=pop_operation_index=0;
	}
};

int T;/*number of test cases*/
/*integers to be scanned every loop*/
/*more global variables*/

/*functions*/

int main(int argc, char const *argv[])
{
	vector<int> numbers;
	vector<int> operations;
	//0==push, 1==>push back 2==>push front, 3==>pop back
	int n;
	char comma;
	while(!cin.eof())
	{
		cin>>n>>comma;
		numbers.pb((n));
	}
	vector<NumberOperation> number_operations(numbers.size()+1);
	int max_pushed = 0;
	int i = 0;
	for(int i=0;i<numbers.size();i++)
	{
		if(numbers[i]>=max_pushed)
		{
			//debug("inside if");
			for (int j = max_pushed+1; j < numbers[i]; ++j)
			{
				operations.pb(0);
				number_operations[j].push_operation_index=operations.size()-1;
			}
			operations.pb(1);
			operations.pb(3);
			number_operations[numbers[i]].push_operation_index = operations.size()-2;
			number_operations[numbers[i]].pop_operation_index = operations.size()-1;
			max_pushed = numbers[i];
		}
		else
		{
			//debug("inside else");
			int pi = number_operations[numbers[i]].push_operation_index;
			if(operations[pi]==0)
				operations[pi] = 1;
			for (int j = numbers[i]+1; j < max_pushed; ++j)
			{
				pi=number_operations[j].push_operation_index;
				//debug("for number ",j," push operation idnex = ",pi," and value of the operation = ",operations[pi]);
				if(operations[pi]!=1)
					operations[pi]=2;
				//debug("after: for number ",j," push operation idnex = ",pi," and value of the operation = ",operations[pi]);
			}
			operations.pb(3);
			number_operations[numbers[i]].pop_operation_index=operations.size()-1;
		}
		//debug(operations);
	}
	debug(operations);
	deque<int> dq;
	int counter=1;
	int outputIndex=0;
	bool impossible=false;
	for (int i = 0; i < operations.size(); ++i)
	{
		//// debug("dq = ",dq);
		if(operations[i]==0)
		{
			impossible=true;
			break;
		}
		if(operations[i]==1)
		{
			dq.push_back(counter++);
		}
		else if(operations[i]==2)
		{
			if(dq.size()==0)
				operations[i]=1;
			dq.push_front(counter++);
		}
		else
		{
			//debug("popping");
			int num = dq.back();
			dq.pop_back();
			if(num!=numbers[outputIndex])
			{
				//debug("diff: ",num, numbers[outputIndex]);
				impossible=true;
				break;
			}
			outputIndex++;
		}
		//// debug("end dq = ",dq);
	}
	//debug(operations);
	if(impossible)
		cout<<"impossible"<<endl;
	else
	{
		string sep="";
		for (int i = 0; i < operations.size(); ++i)
		{
			if(operations[i]==1)
			{
				cout<<sep<<"pushBack";
			}
			else if(operations[i]==2)
			{
				cout<<sep<<"pushFront";
			}
			else
			{
				cout<<sep<<"popBack";
			}
			sep=",";
		}
	}
	return 0;
}
