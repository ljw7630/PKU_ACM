#include <iostream>
#include <cmath>
using namespace std;

int n;
double dp[55][55];
double dis[55][55];
struct PT
{
	int x;
	int y;
}pt[55];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				dp[i][j]=0.0;
		for(int i=1;i<=n;++i)
			scanf("%d%d",&pt[i].x,&pt[i].y);
		for(int i=1;i<n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				dis[i][j]=sqrt((double)(pt[i].x-pt[j].x)*(pt[i].x-pt[j].x)+(pt[i].y-pt[j].y)*(pt[i].y-pt[j].y));
			}
		}
		dp[1][2]=dis[1][2];
		for(int j=3;j<=n;++j)
		{
			for(int i=1;i<=j-2;++i)
				dp[i][j]=dp[i][j-1]+dis[j-1][j];
			dp[j-1][j]=10000000.0;
			double q;
			for(int k=1;k<=j-2;++k)
			{
				q=dp[k][j-1]+dis[k][j];
				if(q<dp[j-1][j])
					dp[j-1][j]=q;
			}
		}
		dp[n][n]=dp[n-1][n]+dis[n-1][n];
		printf("%.2lf\n",dp[n][n]);
	}
	return 0;
}