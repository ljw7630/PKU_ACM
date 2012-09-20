#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n,parent[105];

struct theedge
{
	int i;
	int j;
	double dis;

	bool friend operator < (theedge &a,theedge &b)
	{
		return a.dis<b.dis;
	}
}edge[5050];

struct node
{
	double x;
	double y;
}p[105];

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

double compute(int s,int e)
{
	return sqrt((double)((p[s].x-p[e].x)*(p[s].x-p[e].x)+(p[s].y-p[e].y)*(p[s].y-p[e].y)));
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		double len;
		int c=0;
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				len=compute(i,j);
				edge[c].i=i;
				edge[c].j=j;
				edge[c++].dis=len;
			}
		}
		for(int i=0;i<n;++i)
		{
			parent[i]=i;
		}
		sort(edge,edge+c);
		int count=0;
		double sum=0;
		for(int k=0;k<c&&count<n;++k)
		{
			int fx=findset(edge[k].i);
			int fy=findset(edge[k].j);
			if(fx!=fy)
			{
				parent[fx]=parent[fy];
				sum+=edge[k].dis;
				count++;
			}
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}