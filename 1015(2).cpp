#include <iostream>
using namespace std;
int p[210],d[210],minus[210],plus[210],dp[25][810],path[25][810];
int n,m;

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

bool select(int a,int b, int i)
{
	while(a>0&&path[a][b]!=i)
	{
		b-=minus[path[a][b]];
		a--;
	}
	return (a!=0)?true:false;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,a,b,origin,k,count=1;
	int result[21];
	while(scanf("%d%d",&n,&m)==2&&n!=0)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&p[i],&d[i]);
			plus[i]=p[i]+d[i];
			minus[i]=p[i]-d[i];
		}
		memset(dp,-1,sizeof(dp));
		memset(path,0,sizeof(path));
		origin=m*20;
		for(dp[0][origin]=j=0;j<m;j++)
		{
			for(k=0;k<origin*2;k++)
			{
				if(dp[j][k]>=0)
				{
					for(i=1;i<=n;i++)
					{
						if(dp[j+1][k+minus[i]]<dp[j][k]+plus[i])
						{
							a=j,b=k;
						}
						if(!select(a,b,i))
						{
							dp[j+1][k+minus[i]]=dp[j][k]+plus[i];
							path[j+1][k+minus[i]]=i;
						}
					}
				}
			}
		}
		for(i=origin,j=0;dp[m][i+j]<0 && dp[m][i-j]<0;j++);
		k=dp[m][i+j]>dp[m][i-j]?i+j:i-j;
		printf("Jury #%d\n",count++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",(dp[m][k]+k-origin)/2,(dp[m][k]-k+origin)/2);
		for(i=1;i<=m;i++)
		{
			result[i]=path[m-i+1][k];
			k-=minus[i];
		}
		qsort(result+1,m,sizeof(int),cmp);
		for(i=1;i<=m;i++)
			printf(" %d",result[i]);
		printf("\n\n");
	}
	return 0;
}