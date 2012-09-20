#include <iostream>
using namespace std;

char map[300][300];
int dp[300][210];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	int count=0;
	while(scanf("%d ",&n)!=EOF&&n)
	{
		int sum=0;
		printf("Triangle #%d\n",++count);
		for(int i = 0; i < n; i++) {
			 bool flag = true;
			 char c;
			 for(int j = 0; j < 2 * n; j++) {
					 if(!flag) {
							   map[i][j] = '#';
							   continue;
					 }
					 scanf("%c", &c);
					 if(c == '-')
						  sum = 1;
					 map[i][j] = c;
					 if(c == ' ') 
						  map[i][j] = '#';
					 if(c == '\n') {
						  map[i][j] = '#';
						  flag = false;
					 }
					 
			 }
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<2*n-1;++i)
		{
			if(map[0][i]=='-')
				dp[0][i]=1;
		}
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<2*n-1;++j)
			{
				if(i%2!=j%2)
					continue;
					
				if(map[i][j]=='-')
				{
					dp[i][j]=1;
				}
				else
					continue;
				if(map[i-1][j]=='-')
				{
					int t1=0,t2=0;
					if(j>0)
						t1=dp[i-1][j-1];
					t2=dp[i-1][j+1];
					dp[i][j]=min(t1,t2)+1;
				}
				if(dp[i][j]>sum)
					sum=dp[i][j];
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n/2;++i)
		{
			for(int j=0;j<2*n;++j)
			{
				char temp=map[i][j];
				map[i][j]=map[n-1-i][j];
				map[n-1-i][j]=temp;
			}
		}
		for(int j = 0; j < 2 * n - 1; j++) 
			 if(map[0][j] == '-')  dp[0][j] = 1;
		int flag=0;
		if((n&1)==0)
		{
			flag=1;
		}
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<2*n-1;++j)
			{

				if(((i+j)&1)==flag)
				{
					continue;
				}

				if(map[i][j]=='-')
					dp[i][j]=1;
				else
					continue;
				if(map[i-1][j]=='-')
				{
					int t1=0,t2=0;
					if(j>0)
						t1=dp[i-1][j-1];
						t2=dp[i-1][j+1];
						dp[i][j]=min(t1,t2)+1;
				}
				if(dp[i][j]>sum)
					sum=dp[i][j];
			}
		}
		printf("The largest triangle area is %d.\n\n",sum*sum);
	}
	return 0;
}