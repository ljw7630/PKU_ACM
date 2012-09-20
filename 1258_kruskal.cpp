#include <iostream>
#include <algorithm>
using namespace std;

int n,parent[105];

class node
{
public:
	int x;
	int y;
	int dis;

	bool friend operator <(node &a,node &b)
	{
		return a.dis<b.dis;
	}
}edge[5050];

int findset(int s)
{
	if(s==parent[s])
		return s;
	else
	{
		int fx=findset(parent[s]);
		parent[s]=fx;
		return fx;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		int c=0,value;
		for(int i=0;i<n;++i)
		{
			parent[i]=i;
			for(int j=0;j<n;++j)
			{
				scanf("%d",&value);
				if(i<j)
				{
					edge[c].x=i;
					edge[c].y=j;
					edge[c++].dis=value;
				}
			}
		}
		sort(edge,edge+c);
		int sum=0,count=0;
		for(int i=0;i<c&&count<n;++i)
		{
			int fx=findset(edge[i].x);
			int fy=findset(edge[i].y);
			if(fx!=fy)
			{
				parent[fx]=parent[fy];
				sum+=edge[i].dis;
				count++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}