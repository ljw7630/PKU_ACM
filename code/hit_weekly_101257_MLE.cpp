#include <iostream>
using namespace std;

int t,n,m;
bool map[10005][10005];

void floyd()
{
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(map[i][k]&&map[k][j])
					map[i][j]=true;
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			mycount[i]=0;
			for(int j=1;j<=n;++j)
			{
				map[i][j]=false;
			}
			map[i][i]=true;
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&a,&b);
			map[b][a]=true;
		}
		floyd();
		short maxi=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(map[i][j])
					mycount[i]++;
			}
			if(mycount[i]>maxi)
				maxi=mycount[i];
		}
		for(int i=1;i<=n;++i)
		{
			if(mycount[i]==maxi)
				printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}