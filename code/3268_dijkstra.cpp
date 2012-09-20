#include <iostream>
using namespace std;

const int MAX=10000000;
int n,m,x;
int map[1001][1001];
int maxcost[10001];
bool visit[1001];
int dis[1001];

void dijkstra(int v)
{
	for(int i=1;i<=n;++i)
	{
		dis[i]=map[v][i];
		visit[i]=false;
	}
	dis[v]=0;
	visit[v]=true;

	for(int k=1;k<=n;++k)
	{
		int temp=MAX;
		int u=0;
		for(int i=1;i<=n;++i)
		{
			if(!visit[i]&&dis[i]<temp)
			{
				u=i;
				temp=dis[i];
			}
		}
		visit[u]=true;
		for(int i=1;i<=n;++i)
		{
			if(!visit[i]&&map[u][i]<MAX)
			{
				if(dis[u]+map[u][i]<dis[i])
				{
					dis[i]=dis[u]+map[u][i];
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		maxcost[i]+=dis[i];
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a,b,t;
	while(scanf("%d%d%d",&n,&m,&x)!=EOF)
	{
		for(int i=0;i<=n;++i)
		{
			maxcost[i]=0;
			for(int j=0;j<=n;++j)
			{
				map[i][j]=MAX;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&t);
			map[a][b]=t;
		}
		dijkstra(x);
		int t;
		for(int i=1;i<=n;++i)
		{
			for(int j=i;j<=n;++j)
			{
				t=map[i][j];
				map[i][j]=map[j][i];
				map[j][i]=t;
			}
		}
		dijkstra(x);
		int maxi=0;
		for(int i=1;i<=n;++i)
		{
			if(maxcost[i]>maxi)
				maxi=maxcost[i];
		}
		printf("%d\n",maxi);
	}
	return 0;
}