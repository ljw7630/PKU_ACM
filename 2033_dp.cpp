// if str[i] equal to 0, that means str[i-1] must with str[i] to
// illustrate a value, so dp[i]=dp[i-2] (the case have't increase)

// if temp > 26 or < 10 means str[i-1] must with str[i-2] to illustrate
// a value, seems str[i-1]==0 have been compute when i-1 so, dp[i]=dp[i-1]

// if in normal case, dp[i-2] means str[i] with str[i-1], dp[i-1] means str[i]
// is independent, so dp[i]=dp[i-1]+dp[i-2]


#include <iostream>
using namespace std;

char str[50005];
int dp[50005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int temp,len;
	while(scanf("%s",str)!=EOF&&str[0]!='0')
	{
		memset(dp,0,sizeof(dp));
		len=strlen(str);
		dp[0]=1;
		for(int i=1;i<len;++i)
		{
			temp=(str[i-1]-'0')*10+str[i]-'0';
			if(str[i]=='0')
			{
				if(i>1)
					dp[i]=dp[i-2];
				else
					dp[i]=1;
				if(i>1)
					dp[i-1]=dp[i-2];
			}
			else if(temp>26||temp<10)
			{
				dp[i]=dp[i-1];
			}
			else
			{
				if(i>1)
					dp[i]=dp[i-1]+dp[i-2];
				else
					dp[i]=2;
			}
		}
		printf("%d\n",dp[len-1]);
	}
	return 0;
}