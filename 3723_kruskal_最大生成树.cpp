#include <iostream>
#include <algorithm>
using namespace std;

struct NODE
{
	int boyn;
	int girln;
	int dis;

	bool friend operator <(const NODE &a,const NODE &b)
	{
		return a.dis<b.dis;
	}
}node[50005];

int father[20005];

int findset(int p)
{
	if(father[p]!=p)
		father[p]=findset(father[p]);
	return father[p];
}

void unionset(int p,int q)
{
	int a=findset(p);
	int b=findset(q);
	father[a]=b;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int testcase,n,m,r,i;
	scanf("%d",&testcase);
	while(testcase--)
	{
		scanf("%d%d%d",&n,&m,&r);
		for(i=0;i<r;++i)
		{
			scanf("%d%d%d",&node[i].boyn,&node[i].girln,&node[i].dis);
			node[i].girln+=n;
		}
		for(i=0;i<n+m;++i)
			father[i]=i;
		sort(node,node+r);
		int res=0;
		for(i=r-1;i>=0;--i)
		{
			if(findset(node[i].boyn)!=findset(node[i].girln))
			{
				unionset(node[i].boyn,node[i].girln);
				res+=node[i].dis;
			}
		}
		printf("%d\n",(n+m)*10000-res);
	}
	return 0;
}