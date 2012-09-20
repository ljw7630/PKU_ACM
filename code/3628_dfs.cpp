#include <iostream>
using namespace std;

int n,b,best,c;
int arr[25];

void dfs(int i)
{
	if(i>=n||c>=b)
	{
		if(c-b<best&&c>=b)
			best=c-b;
		return;
	}
	c+=arr[i];
	dfs(i+1);
	c-=arr[i];
	dfs(i+1);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&b)!=EOF)
	{
		best=INT_MAX;
		for(int i=0;i<n;++i)
			scanf("%d",&arr[i]);
		c=0;
		dfs(0);
		printf("%d\n",best);
	}
	return 0;
}