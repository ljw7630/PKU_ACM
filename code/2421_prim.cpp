#include <iostream>
using namespace std;
int a[102][102];
int prim(int v,int n)
{
	int lowcost[102];
	int sum,i,j,mini,t;
	for(i=0;i<n;++i)
		lowcost[i]=a[v][i];
	lowcost[v]=-1;
	sum=0;
	for(i=0;i<n-1;++i)
	{
		mini=INT_MAX;
		for(j=0;j<n;++j)
		{
			if(lowcost[j]==-1)
				continue;
			if(mini>lowcost[j])
			{
				mini=lowcost[j];
				t=j;
			}
		}
		if(lowcost[t]==INT_MAX)
			break;
		lowcost[t]=-1;
		sum+=mini;
		for(j=0;j<n;++j)
			if(a[t][j]<lowcost[j])
				lowcost[j]=a[t][j];
	}
	return sum;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,q;
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				scanf("%d",&a[i][j]);
			}
		}
		scanf("%d",&q);
		int x,y;
		for(i=0;i<q;++i)
		{
			scanf("%d%d",&x,&y);
			a[x-1][y-1]=a[y-1][x-1]=0;
		}
		printf("%d\n",prim(0,n));
	}
	return 0;
}