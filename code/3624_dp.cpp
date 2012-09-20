#include <iostream>
using namespace std;
int dp[13000];
int w[3500],d[3500];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;++i)
			scanf("%d%d",&w[i],&d[i]);
		for(int i=0;i<n;++i)
		{
			for(int j=m;j>=w[i];--j)
			{
				if(dp[j-w[i]]+d[i]>dp[j])
					dp[j]=dp[j-w[i]]+d[i];
			}
		}
		int maxi=0;
		for(int i=0;i<=m;++i)
			if(dp[i]>maxi)
				maxi=dp[i];
		printf("%d\n",maxi);
	}
	return 0;
}