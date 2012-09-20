#include <iostream>
#include <queue>
using namespace std;
const int maxn=1005;
int t,n,s,e,dist;
int map[maxn][maxn];
int len[maxn];
queue<int>q;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	while(scanf("%d%d",&t,&n)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(len,0,sizeof(len));
		for(int i=0;i<t;++i)
		{
			scanf("%d%d%d",&s,&e,&dist);
			if(map[s][e]==0||map[s][e]>dist)
				map[s][e]=map[e][s]=dist;
		}
		while(!q.empty())
			q.pop();
		q.push(n);
		int temp;
		while(!q.empty())
		{
			temp=q.front();
			q.pop();
			for(int i=1;i<=n;++i)
			{
				if(map[temp][i]&&(len[i]==0||(len[i]>map[temp][i]+len[temp])))
				{
					len[i]=map[temp][i]+len[temp];
					q.push(i);
				}
			}
		}
		printf("%d\n",len[1]);
	}
	return 0;
}