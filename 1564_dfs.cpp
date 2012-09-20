#include <iostream>
using namespace std;

int t,n,sum,arr[15],temp[15],c;
bool flag;

void dfs(int indexarr,int sum)
{
	int i;
	if(!sum)
	{
		for(i=1,printf("%d",temp[0]);i<c;++i)
		{
			printf("+%d",temp[i]);
		}
		printf("\n");
		flag=true;
		return;
	}
	if(indexarr>=n||sum<0)
		return;
	for(i=indexarr;i<n;++i)
	{
		if(i==indexarr||arr[i]!=arr[i-1])
		{
			temp[c++]=arr[i];
			dfs(i+1,sum-arr[i]);
			--c;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(true)
	{
		scanf("%d%d",&t,&n);
		if(!t||!n)
			break;
		memset(temp,0,sizeof(temp));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&arr[i]);
		}
		sum=0;
		c=0;
		flag=false;
		printf("Sums of %d:\n",t);
		dfs(0,t);
		if(!flag)
			printf("NONE\n");
	}
	return 0;
}