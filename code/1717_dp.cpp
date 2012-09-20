//dp[i]为左边的数到达和为i的时候需要的最小交换次数
//从当前状态推出下一状态,注意要把以前的状态删掉

#include <iostream>
using namespace std;

int n;
int a[1005];
int dp[12005];

int main()
{
	int i,j;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);	
	while(scanf("%d",&n)!=EOF)
	{
		int sum=0;
		for(i=1;i<12005;++i)
			dp[i]=INT_MAX;
		dp[0]=0;
		int x,y,temp,i,j;
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			sum+=(x+y);
			for(j=sum;j>=0;--j)
			{
				if(dp[j]<INT_MAX)
				{
					temp=dp[j];
					dp[j]=INT_MAX;
					if(dp[j+x]>temp)
						dp[j+x]=temp;
					if(dp[j+y]>temp+1)
						dp[j+y]=temp+1;
				}
			}
		}
		for(i=sum/2;i>=0;--i)
			if(dp[i]<INT_MAX)
				break;
		for(j=(int)((double)sum/2.0+0.5);j<sum;++j)
			if(dp[j]<INT_MAX)
				break;
		printf("%d\n",dp[i]<dp[j]?dp[i]:dp[j]);
	}
	return 0;
}
