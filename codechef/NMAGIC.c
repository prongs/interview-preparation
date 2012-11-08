#include <stdio.h>
#include<string.h>
int main(void) 
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                int len,i,j;
                char str[1000];
                scanf("%s",str);
                len=strlen(str);
                for(i=len-1;i>=0;i--)
                {
                        if(str[i]=='7')
                        str[i]='4';
                        else if(str[i]=='4')
                        {
                                str[i]='7';
                                //j=i-1;
                                //while(j>=0&&str[j]=='4')
                        //      {
                                //str[j]='7';
                                //j--;
                                //printf("\n");
                        //      }
                                break;
                        }
                }
                if(i==-1&&str[0]=='4')
                {
                        //str[i]='4';
                        //i++;
                        //str[i]='\0';
                        printf("4");
                }
                printf("%s\n",str);
                
        } 
        return 0;
}
