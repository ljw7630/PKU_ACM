#include <iostream>
using namespace std;

int num;
int arr[25];
bool flag;

void dfs(int remain,int k)
{
	if(remain<=20)
		return;
	remain-=arr[k];
	if(remain<=20)
	{
		flag=true;
		return;
	}
	for(int i=1;i<=20;++i)
	{
		dfs(remain-i,i);
		if(flag)
			return;
	}
}

int main()
{
	INT_MAX
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&num)!=EOF&&num)
	{
		flag=false;
		arr[0]=0;
		for(int i=1;i<=20;++i)
		{
			scanf("%d",&arr[i]);
		}
		if(num<=20)
		{
			flag=true;
		}
		else
		{
			for(int i=1;i<=20;++i)
			{
				dfs(num-i,i);
				if(flag)
					break;
			}
		}
		if(flag)
		{
			printf("Carl can win\n");
		}
		else
		{
			printf("Carl can't win\n");
		}
	}
	return 0;
}