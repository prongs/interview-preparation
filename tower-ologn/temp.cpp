#include <iostream>
using namespace std;
#define L1 (10000000)
unsigned long long int g[L1+10], ig[L1+10],sg[L1+10];

int main()
{
    g[1] = 1;
    ig[1] = 1;
    sg[1]=1;
    for (int i = 2; i < L1; ++i) {
        // cout<<i<<" ";
        g[i] = 1 + g[i - g[g[i - 1]]];
        // cout<<i<<" ";
        ig[i] = ig[i - 1] + i * g[i];
        // cout<<i<<" ";
        sg[i]=sg[i-1]+g[i];
        // cout<<i<<endl;
    }
    cout<<"hi";
    int k = 1;
    while (ig[k] < 1000000000000000000ULL) // 10^6
    {
        ++k;
    }
    cout<<"k= "<<k<<" and sg[k-1]="<<sg[k-1]<<" and g[k-1]="<<g[k-1]<<" and div="<<(ig[k]-ig[k-1])/(k)<<endl;
    int a=sg[k-1]+(1000000000000000000ULL-ig[k-1])/(k);
    cout<<a;

    return 0;
}
