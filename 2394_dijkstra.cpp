#include <iostream>
using namespace std;

const int maxn=505;
const int inf=1000000000;
int f,p,c,m,start,eend,sec;
int map[maxn][maxn];
int dist[maxn];
bool visit[maxn];

void dijkstra()
{
	dist[1]=0;
	visit[1]=true;
	for(int i=2;i<=f;++i)
	{
		if(map[1][i]==0)
			dist[i]=inf;
		else
			dist[i]=map[1][i];
	}
	for(int i=2;i<=f;++i)
	{
		int u=1;
		int mini=inf;
		for(int j=2;j<=f;++j)
		{
			if(!visit[j]&&mini>dist[j])
			{
				u=j;
				mini=dist[u];
			}
		}
		visit[u]=true;
		for(int j=2;j<=f;++j)
		{
			if(map[u][j]&&dist[j]>dist[u]+map[u][j])
			{
				dist[j]=dist[u]+map[u][j];
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d%d%d",&f,&p,&c,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(dist,0,sizeof(dist));
		memset(visit,false,sizeof(visit));
		for(int i=0;i<p;++i)
		{
			scanf("%d%d%d",&start,&eend,&sec);
			if(map[start][eend]==0||map[start][eend]>sec)
				map[start][eend]=map[eend][start]=sec;
		}
		dijkstra();
		int temp;
		int count=0;
		memset(visit,false,sizeof(visit));
		for(int i=1;i<=c;++i)
		{
			scanf("%d",&temp);
			if(dist[temp]<=m)
			{
				count++;
				visit[i]=true;
			}
		}
		printf("%d\n",count);
		for(int i=1;i<=c;++i)
			if(visit[i])
				printf("%d\n",i);
	}
	return 0;
}