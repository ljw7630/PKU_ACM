#include <iostream>
using namespace std;

const int maxlen=1122;

int p[maxlen];
bool a[maxlen];
int dp[15][maxlen];
int val[maxlen];

int getPrime()
{
	memset(a,false,sizeof(a));
	a[0]=true;
	a[1]=true;
	for(int i=2;i<maxlen;++i)
	{
		if(a[i]==true)
			continue;
		for(int j=2;i*j<maxlen;++j)
		{
			a[i*j]=true;
		}
	}
	int c=0;
	for(int i=2;i<maxlen;++i)
	{
		if(!a[i])
			p[c++]=i;
	}
	return c;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,k;
	int c;
	int maxp=getPrime();
	while(scanf("%d%d",&n,&k)!=EOF&&n&&k)
	{
		memset(dp,0,sizeof(dp));
		dp[k][n]=1;
		c=0;
		for(int i=0;p[i]<=n&&i<maxp;++i)
			val[c++]=p[i];
		for(int t=0;t<c;++t)
		{
			for(int i=1;i<=k;++i)
			{
				for(int j=2;j<=n;++j)
				{
					if(dp[i][j]!=0)
					{
						if(j>=val[t])
						{
							dp[i-1][j-val[t]]+=dp[i][j];
						}
					}
				}
			}
		}
		printf("%d\n",dp[0][0]);
	}
	return 0;
}