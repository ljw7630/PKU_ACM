#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
const int maxn=50005;

struct NODE
{
	int node;
	int len;
};

struct cmp
{
	bool operator() (const int &a,const int &b)
	{
		return a >b;
	}
};

int weight[maxn];
unsigned __int64 dist[maxn];
unsigned __int64 INF;
priority_queue<int,vector<int>,cmp> pq;
vector<NODE>vec[maxn];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,e;
	memset(&INF,0xff,sizeof(INF));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&e);
		for(int i=1;i<=n;++i)
			vec[i].clear(),dist[i]=INF;
		for(int i=1;i<=n;++i)
			scanf("%d",&weight[i]);
		NODE tnode;
		int index;
		for(int i=1;i<=e;++i)
		{
			scanf("%d%d%d",&index,&tnode.node,&tnode.len);
			vec[index].push_back(tnode);
			swap(tnode.node,index);
			vec[index].push_back(tnode);
		}
		while(!pq.empty())
			pq.pop();
		pq.push(1);
		dist[1]=0;
		while(!pq.empty())
		{
			int v=pq.top();
			pq.pop();
			int len=vec[v].size();
			for(int i=0;i<len;++i)
			{
				int tid=vec[v][i].node;
				if(dist[tid]==INF||dist[tid]>dist[v]+vec[v][i].len)
				{
					dist[tid]=dist[v]+vec[v][i].len;
					pq.push(tid);
				}
			}
		}
		unsigned __int64 res=0;
		bool flag=true;
		for(int i=2;i<=n;++i)
		{
			if(dist[i]==INF)
			{
				flag=false;
				break;
			}
			res+=dist[i]*weight[i];
		}
		if(flag)
			printf("%I64u\n",res);
		else
			printf("No Answer\n");
	}
	return 0;
}