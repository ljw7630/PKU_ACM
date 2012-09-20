#include <iostream>

using namespace std;
int dp[60001],num[6],sum;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,pos,counter=0;
	while(true)
	{
		sum=0;
		for(i=0;i<6;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i]*(i+1);
		}
		counter++;
		if(sum==0)
			break;
		if(sum&1)
		{
			printf("Collection #%d:\nCan't be divided.\n\n",counter);
			continue;
		}
		sum>>=1;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(i=0;i<6;i++)
		{
			for(j=sum;j>-1;j--)
			{
				if(dp[j]==0)
				{
					continue;
				}
				if(dp[j+i+1]==1)
				{				
					continue;
				}
				pos=j;
				for(k=0;k<num[i];k++)
				{
					pos+=(i+1);
					if(pos>sum)
						break;
					dp[pos]=1;
				}
			}
		}
		printf("Collection #%d:\n",counter);
		if(dp[sum]==1)
		{
			printf("Can be divided.\n\n");
		}
		else
		{
			printf("Can't be divided.\n\n");
		}
	}
	return 0;
}