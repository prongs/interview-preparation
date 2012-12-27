#include<stdio.h>
int N, m,p,i,j,nums[10001],q;
int main()
{
    scanf("%d", &N);
    for( i=0; i<N ; i++ )
    {
        q=0;
        memset(nums, 0, sizeof(nums));
        scanf("%d", &m);
        for( j=0; j<m ; j++ )
        {
            scanf("%d", &p);
            nums[p]=nums[p]+1;
            if( nums[p]>nums[q] )
            {
                q=p;
            }
        }
        printf("%d %d", q, nums[q]);
    }
}
