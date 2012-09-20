#include <iostream>
using namespace std;

int n;
int a[1005];
int dp[1005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			dp[i]=1;
		}
		int maxi=1;
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<i;++j)
			{
				if(a[i]>a[j]&&dp[i]<dp[j]+1)
				{
					dp[i]=dp[j]+1;
					if(maxi<dp[i])
						maxi=dp[i];
				}
			}
		}
		printf("%d\n",maxi);
	}
	return 0;
}