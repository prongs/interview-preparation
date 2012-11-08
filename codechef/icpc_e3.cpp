// Ideone_Language_Id:1
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <set>
#include <utility>
#include <stack>
#include <cmath>
#include <cassert>
#include <stdio.h>

#define s(n) scanf("%d",&n)
#define p(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%f\n",n)
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c\n",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s\n",n)



#define fill(a,v) memset(a,v,sizeof a)
#define all(a) a.begin(),a.end()
#ifdef DEBUG
	#define debug(args...) {dbg,args;std::cerr<<std::endl;}
#else
	#define debug(args...) // Just strip off all debug tokens
#endif
struct debugger{template<typename T> debugger& operator ,(const T& v){std::cerr<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline std::ostream& operator<<(std::ostream& os,const std::pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::vector<T>& v){bool first=true;std::string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::set<T>& v){bool first=true;std::string delim="[";for (typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline std::ostream&operator<<(std::ostream& os,const std::map<T1,T2>& v){bool first=true;std::string delim="[";for (typename std::map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
struct cd_struct
{
	int c; int d; int ind; int result;
	cd_struct(int u, int v, int w)
	{
		c=u;d=v;ind=w;result=0;
	}
};
typedef struct cd_struct cd_struct;
inline std::ostream&operator<<(std::ostream &os, const cd_struct &cds){return os<<"( "<<cds.c<<" "<<cds.d<<" "<<cds.ind<<" "<<cds.result<<" )";}
using namespace std;

#define MOD 1000000007
#define INF  2147483647
int a[1000001],b[1000001],m[1000001],l[1000001];
vector<int> v;
vector<cd_struct> cds;
int t,n,q,c,d,x,y,outer_d,outer_c;
char str[100010] = {0};

bool dCompare(cd_struct p1, cd_struct p2)
{
	return (p1.d<p2.d || (p1.d==p2.d && p1.c<=p2.c));
}
bool qCompare(cd_struct p1, cd_struct p2)
{
	return p1.ind>p2.ind;
}
int main(){
	scanf("%d", &t);
	// debug(t);
	while(t--){
		fill(str, 0);
		scanf("%d", &n);
		scanf("%s", str);
		scanf("%d", &q);
		// debug(n,s,q);
		int Q = q;
		cds.clear();
		while(q--){
			s(c);s(d);
			cds.push_back(cd_struct(c-1,d-1,q));
		}
		sort(all(cds), dCompare);
		debug(cds);
		outer_d = -1;
		for (int i = 0; i < Q; ++i)
		{
			int newd = cds[i].d;
			int newc = cds[i].c;
			if(newd!=outer_d)
			{
				outer_d=newd;
				fill(a,0);
				fill(b,0);
				x=0;y=0;
				if(str[newd]=='0'){
					a[newd]=1;
					x=1;
					b[newd]=1;
				}
				else{
					a[newd]=1;
					y=1;
					b[newd]=1;
				}
				int k=newd-1;
				while(k>=newc){
					if(str[k]=='0'){
						a[k]=1+max(x,y);
						x=a[k];
					}
					else{
						a[k]=1+y;
						y=a[k];
					}
					b[k]= max(x,y);
					if(newd==13)
						debug(k,newd, x,y);
					k--;
				}
			}
			cds[i].result = b[newc];
		}
		sort(all(cds), qCompare);
		debug(cds);
		for (int i = 0; i < Q; ++i)
		{
			printf("%d\n", cds[i].result);
		}
	}
	return 0;
}

