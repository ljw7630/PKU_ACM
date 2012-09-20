#include <iostream>
#include <algorithm>
using namespace std;
int parent[102],n;
bool flag[102];
class node
{
public:
	int x,y;
	int dis;
	bool friend operator<(node &a,node &b)
	{
		return a.dis<b.dis;
	}
}edge[10005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int nodetag;
	while(scanf("%d",&n)!=EOF)
	{
		memset(flag,false,sizeof(flag));
		nodetag=1;
		for(int i=1;i<=n;++i)
		{
			parent[i]=i;
			for(int j=1;j<=n;++j)
			{
				scanf("%d",&edge[nodetag].dis);
				edge[nodetag].x=i;
				edge[nodetag].y=j;
				++nodetag;
			}
		}
		sort(edge+1,edge+nodetag);
		nodetag=n+1;  //前面有n个0
		int count=0,sum=0;
		while(count<n-1)
		{
			if((!flag[edge[nodetag].x])&&(!flag[edge[nodetag].y]))
			{
				sum+=edge[nodetag].dis;
				count++;
				flag[edge[nodetag].x]=true;
				flag[edge[nodetag].y]=true;
				parent[edge[nodetag].x]=parent[edge[nodetag].y];
			}
			else if((!flag[edge[nodetag].x])&&(flag[edge[nodetag].y]))
			{
				sum+=edge[nodetag].dis;
				count++;
				flag[edge[nodetag].x]=true;
				parent[edge[nodetag].x]=parent[edge[nodetag].y];
			}
			else if((flag[edge[nodetag].x])&&(!flag[edge[nodetag].y]))
			{
				sum+=edge[nodetag].dis;
				count++;
				flag[edge[nodetag].y]=true;
				parent[edge[nodetag].y]=parent[edge[nodetag].x];
			}
			else
			{
				if(parent[edge[nodetag].x]!=parent[edge[nodetag].y])
				{
					sum+=edge[nodetag].dis;
					count++;
					int temp=edge[nodetag].y;
					for(int i=1;i<=n;++i)
					{
						if(parent[i]==temp)
						{
							parent[i]=parent[edge[nodetag].x];
						}
					}
				}
			}
			nodetag++;
		}
		printf("%d\n",sum);
	}
	return 0;
}