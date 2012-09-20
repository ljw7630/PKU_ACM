#include <iostream>
using namespace std;
int n,m,s,num;
const double eps=1e-8;
double money,dis[101];
struct edge
{
	int u,v;
	double r,c;
}e[202];

bool bellmanford()
{
	bool flag;
	memset(dis,0,sizeof(dis));
	dis[s]=money;
	while(dis[s]<=money+eps)
	{
		flag=false;
		for(int i=0;i<num;++i)
		{
			if(dis[e[i].v]+eps<(dis[e[i].u]-e[i].c)*e[i].r)
			{
				dis[e[i].v]=(dis[e[i].u]-e[i].c)*e[i].r;
				flag=true;
			}
		}
		if(!flag)
			return dis[s]>money+eps;
	}
	return true;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double rab,rba,cab,cba;
	int u,v;
	while(scanf("%d%d%d%lf",&n,&m,&s,&money)!=EOF)
	{
		num=0;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%lf%lf%lf%lf",&u,&v,&rab,&cab,&rba,&cba);
			e[num].u=u;
			e[num].v=v;
			e[num].r=rab;
			e[num++].c=cab;
			e[num].u=v;
			e[num].v=u;
			e[num].r=rba;
			e[num++].c=cba;
		}
		if(bellmanford())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}