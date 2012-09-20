#include <iostream>
using namespace std;
char x[502],y[502];
int dp[502][502],len1,len2;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j;
	x[0]=y[0]='`';
	while(scanf("%s%s",&x[1],&y[1])!=EOF&&x[1]!='\0')
	{
		len1=strlen(x);
		len2=strlen(y);
		memset(dp,0,sizeof(dp));
		for(i=0;i<len1;i++)
			dp[i][0]=0;
		for(i=0;i<len2;i++)
			dp[0][i]=0;
		for(i=1;i<len1;i++)
		{
			for(j=1;j<len2;j++)
			{
				if(x[i]==y[j])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[len1-1][len2-1]);
	}
	return 0;
}