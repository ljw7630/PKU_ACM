#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sd[27]={'2','2','2','3','3','3','4','4','1','1','5','5','6','6','0','7','0','7','7','8','8','8','9','9','9','0'};
char str[200],s[50010][105],num[50010][105];
int leng[50010];
int word[200];
int pre[200];
int dp[200];
int len;

int min(int a,int b)
{
	return a<b?a:b;
}

void output(int i)
{
	if(pre[i]>0)
	{
		output(pre[i]);
		if(pre[i])
			printf(" ");
	}
	printf("%s",s[word[i]]);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,i,j;
	scanf("%s",&str[1]);
	memset(pre,-1,sizeof(pre));
	memset(word,-1,sizeof(word));
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%s",s[i]);
		leng[i]=strlen(s[i]);
		for(j=0;j<leng[i];++j)
			num[i][j]=sd[s[i][j]-'a'];
	}
	len=strlen(&str[1]);
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(i=1;i<=len;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i>=leng[j]&&strncmp(&str[i-leng[j]+1],num[j],leng[j])==0)
			{
				if(dp[i-leng[j]]==-1)
					continue;
				int temp;
				if(dp[i]==-1)
				{
					temp=dp[i-leng[j]]+1;
				}
				else
				{
					temp=min(dp[i],dp[i-leng[j]]+1);
				}
				if(temp!=dp[i])
				{
					dp[i]=dp[i-leng[j]]+1;
					word[i]=j;
					pre[i]=i-leng[j];
				}
			}
		}
	}
	if(dp[len]<0)
		printf("No solution.\n");
	else
	{
		output(len);
		printf("\n");
	}
	return 0;
}

