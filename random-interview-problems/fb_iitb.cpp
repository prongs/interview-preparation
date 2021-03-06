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
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::set<T>& v){std::string delim="[";for (typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline std::ostream&operator<<(std::ostream& os,const std::map<T1,T2>& v){std::string delim="[";for (typename std::map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}


using namespace std;

struct Node
{
	vector<int> nextNodes;
	bool visited;bool schoolReachable; bool current;
	Node(){
		visited=false;schoolReachable=current=false;nextNodes=vector<int>();
	}
};

int T;/*number of test cases*/
int n,m,home,school;/*integers to be scanned every loop*/
vector<Node>nodes; int numreachables;

bool dfs(int n)
{
	// debug(n);
	if(nodes[n].visited)
	{
		// nodes[n].visited=false;
		return nodes[n].schoolReachable;
	}
	if(n==school)
	{
		nodes[school].schoolReachable=true;
		nodes[school].visited=true;
		numreachables++;
		return true;
	}
	bool reachable=false;	
	nodes[n].visited=true; //have to do it here to avoid infinite loop.
	for (int i = 0; i < nodes[n].nextNodes.size(); ++i)
	{
		reachable |= dfs(nodes[n].nextNodes[i]);
	}
	if(reachable)
	{
		numreachables++;
		nodes[n].schoolReachable=true;
		return true;
	}
	return false;

}
bool dfs2(int n)
{
	debug(n);
	nodes[n].current=true;
	if(nodes[n].schoolReachable)
	{
		return true;
	}
	// if(n==school||(nodes[n].schoolReachable&&!nodes[n].current))
	// 	return true;
	else
	{
		bool reachable = false;
		int numcurreachable=0;
		nodes[n].current=false;
		for (int i = 0; i < nodes[n].nextNodes.size(); ++i)
		{
			bool r = dfs2(nodes[n].nextNodes[i]);
			if(r)
				numcurreachable++;
			reachable|=(r?true:false);
		}
		nodes[n].schoolReachable=reachable;
		debug(numcurreachable);
		if(numcurreachable>1)
			nodes[n].schoolReachable=true;
		return reachable;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	s(T);
	while(T--)
	{
		s(n);s(m);s(home);s(school);
		nodes = vector<Node>(n);
		for (int i = 0; i < m; ++i)
		{
			int from,to;
			s(from);s(to);
			nodes[from].nextNodes.pb(to);
			nodes[to].nextNodes.pb(from);
		}
		numreachables=0;
		dfs(home);
		for (int i = 0; i < n; ++i)
		{
			if(!nodes[i].schoolReachable)
				dfs2(i);
		}
		numreachables=0;
		for (int i = 0; i < n; ++i)
		{
			if(nodes[i].schoolReachable)
				numreachables++;
		}
		p(numreachables);
	}
	
	return 0;
}
