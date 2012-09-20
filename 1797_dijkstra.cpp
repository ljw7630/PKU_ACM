#include <iostream>
#include <algorithm>
using namespace std;

long map[1005][1005];
long dis[1005];
bool used[1005];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,m;
	long x,y,l;
	scanf("%d",&t);
	int s=t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(used,false,sizeof(used));
		memset(map,0,sizeof(map));
		int c=0;
		for(int i=0;i<m;++i)
		{
			scanf("%ld%ld%ld",&x,&y,&l);
			map[x][y]=map[y][x]=l;
		}
		for(int i=1;i<=n;++i)
			dis[i]=map[1][i];
		for(int i=0;i<n-1;++i)
		{
			int pos=0;
			long d=0;
			for(int j=2;j<=n;++j)
				if(!used[j]&&dis[j]>d)
					d=dis[j],pos=j;
			used[pos]=true;
			for(int j=2;j<=n;++j)
				if(!used[j]&&min(dis[pos],map[pos][j])>dis[j]) // 如果源到pos的流量和pos到j的流量的最小值大于源到j的流量,则更新流量
					dis[j]=min(dis[pos],map[pos][j]);
		}
		printf("Scenario #%d:\n%ld\n\n",s-t,dis[n]);
	}
	return 0;
}