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

struct Cell
{
	int crossableLights_pp; int crossableLights_pn; int crossableLights_np; int crossableLights_nn;
	bool hasLight;
	Cell(){crossableLights_nn = crossableLights_pn = crossableLights_np = crossableLights_pp =-1;hasLight=false;}
};

int T;/*number of test cases*/
int N,M,K;/*integers to be scanned every loop*/

Cell cells[1600][1600];

int calculateLights_pp(int begin_row, int begin_col, int row, int col, int count, bool ret);
int calculateLights_pn(int begin_row, int begin_col, int row, int col, int count, bool ret);
int calculateLights_nn(int begin_row, int begin_col, int row, int col, int count, bool ret);
int calculateLights_np(int begin_row, int begin_col, int row, int col, int count, bool ret);


int calculateLights_pp(int begin_row, int begin_col, int row, int col, int count, bool ret)
{
	if(ret&&row==begin_row&&col==begin_col)
		return count;
	row++;col++;
	if(row<N&&col<M)
	{
		calculateLights_pp(begin_row, begin_col, row,col,count+(cells[row][col].hasLight?1:0),true);
	}
	else if(row>=N&&col<M)
	{
		calculateLights_np(begin_row, begin_col,row-2,col,count+(cells[row][col].hasLight?1:0),true);
	}
	else if(row<N&&col>=M)
	{
		calculateLights_pn(begin_row, begin_col,row,col-2,count+(cells[row][col].hasLight?1:0),true);
	}
	else
	{
		calculateLights_nn(begin_row, begin_col,row-2,col-2,count+(cells[row][col].hasLight?1:0),true);
	}

}

int calculateLights_pn(int begin_row, int begin_col, int row, int col, int count, bool ret)
{
	if(ret&&row==begin_row&&col==begin_col)
		return count;
	row++;col--;
	if(row<N&&col>=0)
	{
		calculateLights_pn(begin_row, begin_col, row,col,count+(cells[row][col].hasLight?1:0),true);	
	}
	else if(row<N&&col<0)
	{
		calculateLights_pp(begin_row, begin_col, row,col+2,count+(cells[row][col].hasLight?1:0),true);	
	}
	else if(row>=N&&col>=0)
	{
		calculateLights_nn(begin_row, begin_col, row-2,col,count+(cells[row][col].hasLight?1:0),true);	
	}
	else
	{
		calculateLights_np(begin_row, begin_col, row-2,col+2,count+(cells[row][col].hasLight?1:0),true);	
	}
}

int calculateLights_np(int begin_row, int begin_col, int row, int col, int count, bool ret)
{
	if(ret&&row==begin_row&&col==begin_col)
		return count;
	row--;col++;
	if(col<M&&row>=0)
	{
		calculateLights_np(begin_row, begin_col, row,col,count+(cells[row][col].hasLight?1:0),true);	
	}
	else if(col<M&&row<0)
	{
		calculateLights_pp(begin_row, begin_col, row+2,col,count+(cells[row][col].hasLight?1:0),true);	
	}
	else if(col>=M&&row>=0)
	{
		calculateLights_nn(begin_row, begin_col, row,col-2,count+(cells[row][col].hasLight?1:0),true);	
	}
	else
	{
		calculateLights_pn(begin_row, begin_col, row+2,col-2,count+(cells[row][col].hasLight?1:0),true);	
	}	
}

int calculateLights_nn(int begin_row, int begin_col, int row, int col, int count, bool ret)
{
	if(ret&&row==begin_row&&col==begin_col)
		return count;
	row--;col--;
	if(row>=0&&col>=0)
	{
		calculateLights_nn(begin_row, begin_col, row,col,count+(cells[row][col].hasLight?1:0),true);
	}
	else if(row<0&&col>=0)
	{
		calculateLights_pn(begin_row, begin_col,row+2,col,count+(cells[row][col].hasLight?1:0),true);
	}
	else if(row>=0&&col<0)
	{
		calculateLights_np(begin_row, begin_col,row,col+2,count+(cells[row][col].hasLight?1:0),true);
	}
	else
	{
		calculateLights_pp(begin_row, begin_col,row+2,col+2,count+(cells[row][col].hasLight?1:0),true);
	}
	
}

int main(int argc, char const *argv[])
{

	s(N);s(M);s(K);
	for (int i = 0; i < K; ++i)
	{
		int row,col;
		s(row);s(col);
		cells[row][col].hasLight=true;
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if(cells[i][j].crossableLights_pp==-1)
				cells[i][j].crossableLights_pp=calculateLights_pp(i,j,i,j,cells[i][j].hasLight?1:0,false);

			if(cells[i][j].crossableLights_pn==-1)
				cells[i][j].crossableLights_pn=calculateLights_pn(i,j,i,j,cells[i][j].hasLight?1:0,false);

			if(cells[i][j].crossableLights_np==-1)
				cells[i][j].crossableLights_np=calculateLights_np(i,j,i,j,cells[i][j].hasLight?1:0,false);

			if(cells[i][j].crossableLights_nn==-1)
				cells[i][j].crossableLights_nn=calculateLights_nn(i,j,i,j,cells[i][j].hasLight?1:0,false);
			debug(i,j,cells[i][j].crossableLights_pp,cells[i][j].crossableLights_nn,cells[i][j].crossableLights_pn,cells[i][j].crossableLights_np)
		}
	}
	debug("Done!");


	return 0;
}
