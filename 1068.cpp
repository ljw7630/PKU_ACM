#include <iostream>
using namespace std;
int t,n,p[40],w[40];
bool used[40];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(used,false,sizeof(used));
		k=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
            for(j=p[i]-1;j>=0;j--)
            {
                if(used[j]==false)
                {
                    w[k]=p[i]-j;
                    used[j]=true;
                    k++;
					break;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d",w[i]);
            if(i!=n-1)
            printf(" ");
            }
		printf("\n");
    }
    return 0;
    }
