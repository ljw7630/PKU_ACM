#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn=105;
struct node
{
	int pid;
	int dist;
	int toll;
	bool friend operator <(const node &a,const node &b)
	{
		if(a.dist!=b.dist)
			return a.dist>b.dist;
		else
			return a.toll>b.toll;
	}
};

vector<node> vec[maxn];
int dis[maxn];
priority_queue<node> pq;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int k,n,road,s;
	while(scanf("%d",&k)!=EOF)
	{
		scanf("%d%d",&n,&road);
		node tempnode;
		for(int i=1;i<=n;++i)
		{
			dis[i]=INT_MAX;
			vec[i].clear();
		}
		for(int i=0;i<road;++i)
		{
			scanf("%d%d%d%d",&s,&tempnode.pid,&tempnode.dist,&tempnode.toll);
			vec[s].push_back(tempnode);
		}
		while(!pq.empty())
			pq.pop();
		tempnode.pid=1,tempnode.dist=tempnode.toll=0;
		dis[1]=0;
		pq.push(tempnode);
		while(!pq.empty())
		{
			tempnode=pq.top();
			pq.pop();
			int id=tempnode.pid;
			dis[id]=tempnode.dist;
			if(id==n)
				break;
			node newnode;
			for(int i=0;i<vec[id].size();++i)
			{
				if(tempnode.toll+vec[id][i].toll<=k)
				{
					newnode.pid=vec[id][i].pid;
					newnode.dist=tempnode.dist+vec[id][i].dist;
					newnode.toll=tempnode.toll+vec[id][i].toll;
					pq.push(newnode);
				}
			}
		}
		if(dis[n]!=INT_MAX)
			printf("%d\n",dis[n]);
		else
			printf("-1\n");
	}

	return 0;
}