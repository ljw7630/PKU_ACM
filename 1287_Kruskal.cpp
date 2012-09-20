#include <iostream>
#include <algorithm>
using namespace std;
int p,r,cal;
int c[52][52];
int parent[52];
class Edge
{
public:
	int x,y,value;
	bool friend operator<(Edge &a,Edge&b)
	{
		return a.value<b.value;
	}
}e[10005];

int findparent(int son)
{
	if(parent[son]==son)
		return son;
	int father=findparent(parent[son]);
	parent[son]=father;
	return father;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,x,y,v,sum,px,py;
	while(scanf("%d",&p)&&p!=0)
	{
		scanf("%d",&r);
		for(i=1;i<=p;i++)
			for(j=1;j<=p;j++)
				c[i][j]=INT_MAX;
		for(i=0;i<r;i++)
		{
			scanf("%d%d%d",&x,&y,&v);
			if(c[x][y]>v)
				c[x][y]=c[y][x]=v;
		}
		for(cal=0,i=1;i<=p;i++)
		{
			for(j=1;j<i;j++)
			{
				if(c[i][j]<INT_MAX)
				{
					e[cal].x=i;
					e[cal].y=j;
					e[cal].value=c[i][j];
					cal++;
				}
			}
		}
		sort(e,e+cal);
		for(i=1;i<=p;i++)
			parent[i]=i;
		for(j=1,sum=i=0;i<cal;i++)
		{
			px=findparent(e[i].x);
			py=findparent(e[i].y);
			if(px!=py)
			{
				j++;
				parent[px]=py;
				sum+=e[i].value;
			}
			if(j==p)
				break;
		}
		printf("%d\n",sum);
	}
	return 0;
}