#include "stdio.h"
#include "string.h"
int myDivide(int *a,int len)
{
    int i=0;
    int residue=0;
    int temp=0;
    int next=0;
    for(i=0; i<len; i++)
    {
        temp=a[i]+next;
        a[i]=temp/8;
        residue=temp%8;
        next=residue*10;
    }
    while (next)
    {
        a[i++]=next/8;
        next%=8;
        next*=10;
    }
    return i;
}
void main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int i=0;
    char str[1000];
    int a[3000];
    int len=0;
    int len_a=0;
    while(scanf("%s",str)!=EOF)
    {
        len=strlen(str);
        for(i=0; i<len; i++)
            if (str[i]!='0' && i!=1)
                break;
            if (i==len)
                printf("%s [8] = 0 [10]\n",str);
            else if (str[0]=='1')
                printf("%s [8] = 1 [10]\n",str);
            else
            {
                len_a=1;
                a[0]=str[len-1]-48;
                for(i=len-2; i>0; i--)
                {
                    len_a=myDivide(a,len_a);
                    a[0]=str[i]-48;
                }
                printf("%s [8] = 0.",str);
                for(i=1; i<len_a; i++)
                    printf("%d",a[i]);
                printf(" [10]\n");
            }
       }
}


