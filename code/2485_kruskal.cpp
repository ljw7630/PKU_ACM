#include <iostream>
#include <algorithm>
using namespace std;

int n,parent[505];

class node
{
public:
	int x;
	int y;
	int dis;

	bool friend operator < (node &a, node &b)
	{
		return a.dis<b.dis;
	}
}edge[130000];

int findset(int s)
{
	if(parent[s]==s)
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
	int t,value;
	scanf("%d",&t);
	
	while(t--)
	{
		int c=0;
		scanf("%d",&n);
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
		int count=0;
		int rec=0;
		for(int i=0;i<c&&count<n;++i)
		{
			int fx=findset(edge[i].x);
			int fy=findset(edge[i].y);
			if(fx!=fy)
			{
				parent[fx]=parent[fy];
				if(edge[i].dis>rec)
					rec=edge[i].dis;
				count++;
			}
		}
		printf("%d\n",rec);
	}

	return 0;
}