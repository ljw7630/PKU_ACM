//最大团问题

#include <iostream>
using namespace std;
int n,x[27];
bool isLink[27][27];
char a[30];
int best,count;
void backtrack(int i)
{
	bool ok=true;
	if(i>=n)
	{
		best=count;
		return;
	}
	for(int j=0;j<i;j++)
	{
		if(x[j]==1&&!isLink[i][j]) // 相连
		{
			ok=false;
			break;
		}
	}
	if(ok)
	{
		x[i]=1;
		++count;
		backtrack(i+1);
		--count;
	}
	if(count+n-i>best)
	{
		x[i]=0;
		backtrack(i+1);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		memset(isLink,false,sizeof(isLink));
		memset(x,0,sizeof(x));
		for(int i=0;i<n;i++)
		{
			scanf("%s",a);
			for(int j=2;j<strlen(a);j++)
			{
				isLink[i][a[j]-'A']=true;
			}
		}
		best=0;
		count=0;
		backtrack(0);
		if(best>1)
			printf("%d channels needed.\n",best);
		else
			printf("%d channel needed.\n",best);
	}
	return 0;
}