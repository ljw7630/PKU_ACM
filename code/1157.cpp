#include <iostream>
using namespace std;
int dp[102][102],a[102][102],f,v;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k;
	while(scanf("%d%d",&f,&v)!=EOF)
	{
		for(i=1;i<=f;i++)
		{
			dp[i][0]=0;
			for(j=1;j<=v;j++)
			{
				scanf("%d",&a[i][j]);
				dp[i][j]=INT_MIN;
			}
		}
		for(i=1;i<=f;i++)
		{
			for(j=i;j<=v;j++)
			{
				for(k=i;k<=j;k++)
				{
					if(dp[i][j]<dp[i-1][k-1]+a[i][k]||dp[i][j]==INT_MIN)
					{
						dp[i][j]=dp[i-1][k-1]+a[i][k];
					}
				}
			}
		}
		printf("%d\n",dp[f][v]);
	}
	return 0;
}