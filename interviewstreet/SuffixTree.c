// Input macros
#define s(n)                        scanf("%d",&n)
#define p(n)                        printf("%d",n)
#define sc(n)                       scanf("%c",&n)
#define pc(n)                       printf("%c",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)                       printf("%lld",n)
#define sf(n)                       scanf("%lf",&n)
#define pf(n)                       printf("%lf",n)
#define ss(n)                       scanf("%s",n)
#define ps(n)                       printf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
#include<stdio.h>

#define MAX_NUM_STRINGS 100
#define MAX_LEN_STRING 256 
typedef struct Node
{
    struct Node* parent;
    struct Node* children[26];
}Node;
Node root;
int T, n, num_strings;
int i,j,k,l;
char strings[MAX_LEN_STRING][MAX_NUM_STRINGS];
int main()
{
    s(num_strings);
    for(i=0;i<num_strings; i++)
    {
       ss() 
    }
}

