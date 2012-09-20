#include <iostream>
using namespace std;
int num;
char s1[201],s2[201],s3[402];
int len1,len2,len3;
int dp[201][201];

int recursive(int i,int j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i==0&&j==0)
		return dp[i][j]=1;
	if(i>0&&s3[i+j]==s1[i])
	{
		if(recursive(i-1,j))
		{
			return dp[i][j]=1;
		}
	}
	if(j>0&&s3[i+j]==s2[j])
	{
		if(recursive(i,j-1))
		{
			return dp[i][j]=1;
		}
	}
	return dp[i][j]=0;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int c,i,j,a,b;
	int x,y,count;
	scanf("%d",&num);
	c=num;
	while(num--)
	{
		scanf("%s %s %s",s1+1,s2+1,s3+1);
		s1[0]=' ',s2[0]=' ',s3[0]=' ';
		len1=strlen(s1);
		len2=strlen(s2);
		len3=strlen(s3);
		memset(dp,-1,sizeof(dp));
		printf("Data set %d: ",c-num);
		if(recursive(len1-1,len2-1))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}