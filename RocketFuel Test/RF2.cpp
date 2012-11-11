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

struct Racer
{
	int racerId;long long int startTime;long long int endTime; int score; int bucket;
	Racer(int a,long long int b, long long int c)
	{
		racerId=a;startTime=b;endTime=c;score=0;
	}
	Racer()
	{score=0;}
};
struct Bucket
{
	int no_racers; long long int range_start; long long int range_end;
	Bucket(){no_racers=0;range_start=1000000000000000000;range_end=0;}
};
int T;/*number of test cases*/
int racerId;long long int startTime,endTime;/*integers to be scanned every loop*/
vector<Racer> racers;/*more global variables*/

bool startTimeSortFun(int r1,int r2)
{
	return racers[r1].startTime<racers[r2].startTime;
}
bool endTimeSortFun(int r1,int r2)
{
	return racers[r1].endTime<racers[r2].endTime;
}
bool scoreSort(const Racer& r1, const Racer& r2)
{
	return (r1.score<r2.score)||(r1.score==r2.score&&r1.racerId<r2.racerId);
}
#define K (300)
int main(int argc, char const *argv[])
{
	/* code */
	s(T);
	racers = vector<Racer>(T);
	for(int i = 0;i<T;i++)
	{
		s(racerId);s(startTime);s(endTime);
		racers[i].racerId=racerId;
		racers[i].startTime=startTime;
		racers[i].endTime=endTime;
	}
	vector<int> racerInds(T);
	for (int i = 0; i < T; ++i)
	{
		racerInds[i] = i;
	}
	vector<int> racerInds2(all(racerInds));
	sort(all(racerInds),startTimeSortFun);
	int numBuckets = T/K;
	if(T%K>0)
		numBuckets++;
	vector<Bucket> buckets(numBuckets);
	int curBucket=0;
	int numCurBucket=0;
	for (int i = 0; i < T; ++i)
	{
		racers[racerInds[i]].bucket = curBucket;
		buckets[curBucket].range_start = MIN(buckets[curBucket].range_start,racers[racerInds[i]].startTime);
		buckets[curBucket].range_end   = MAX(buckets[curBucket].range_end,  racers[racerInds[i]].startTime);
		numCurBucket++;
		if(numCurBucket==300)
		{
			curBucket++;
			numCurBucket=0;
		}
	}
	sort(all(racerInds2),endTimeSortFun);
	for (int i = 0; i < T; ++i)
	{
		Racer* cur_racer = &racers[0]+racerInds2[i];
		cur_racer->score=0;
		for (int j = cur_racer->bucket+1; j < numBuckets; ++j)
		{
			cur_racer->score+=buckets[j].no_racers;
		}
		//Check in the current bucket
		for (int k = K*cur_racer->bucket; k < MIN(K*(cur_racer->bucket+1), T); ++k)
		{
			Racer* other_racer = &racers[0]+racerInds[k];
			if(other_racer->startTime>cur_racer->startTime&&other_racer->endTime<cur_racer->endTime)
				cur_racer->score++;
		}
		buckets[cur_racer->bucket].no_racers++;
	}
	sort(all(racers),scoreSort);
	for (int i = 0; i < T; ++i)
	{
		cout<<racers[i].racerId<<" "<<racers[i].score<<endl;
	}
	return 0;
}
