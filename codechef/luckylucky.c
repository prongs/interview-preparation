#include "macros.h"
int T,N,div,mod;
int num4(int N)
{
    int temp=0;
    div=N/7;
    mod=N%7;
    temp=mod%4;
    /*switch(mod)*/
    /*{*/
        /*case 1:*/
            /*temp=1;*/
            /*break;*/
        /*case 2:*/
            /*temp=2;*/
            /*break;*/
        /*case 3:*/
            /*temp=3;*/
            /*break;*/
        /*case 4:*/
            /*temp=0;*/
            /*break;*/
        /*case 5:*/
            /*temp=1;*/
            /*break;*/
        /*case 6:*/
            /*temp=2;*/
            /*break;*/
    /*}*/
    if(div-temp>=0)
    {
        div=div-temp;
        mod=temp*7+mod;
        return div*7;
    }
    else
    {
        return -1;
    }
}
int main()
{
    s(T);
    while(T--)
    {
        s(N);
        p(num4(N));
    }
}
