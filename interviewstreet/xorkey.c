#include<stdio.h>
#define MAXSZ (100000)
short T,N,Q,xs[MAXSZ],i,j,k,l,a,p,q,max;
int main()
{
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&N,&Q);
        for(j=0;j<N;j++)
        {
            scanf("%d",xs+j);
        }
        for(j=0;j<Q;j++)
        {
            scanf("%d %d %d",&a,&p,&q);
            max=0;
            for(k=p-1;k<q;k++)
            {
                l=a^xs[k];
                max=max>l?max:l;
            }
            printf("%d\n",max);
        }
    }
}
