#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int map[101],best[101];
int N,K,T;
class gangster
{
public:
	int t,s,p;
	bool friend operator <(gangster a,gangster b)
	{
		return a.t<b.t;
	}
};
gangster g[101];

int absolute(int a)
{
	return a>0?a:-a;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,result;
	while(scanf("%d%d%d",&N,&K,&T)!=EOF)
	{
		for(i=0;i<N;i++) scanf("%d",&g[i].t);
		for(i=0;i<N;i++) scanf("%d",&g[i].p);
		for(i=0;i<N;i++) scanf("%d",&g[i].s);
		sort(g,g+N);
		result=0;
		for(i=0;i<N;i++)
		{
			best[i]=-1;
			if(g[i].t>=g[i].s)
				best[i]=0;
			for(j=0;j<i;j++)
			{
				if(absolute(g[i].s-g[j].s)<=g[i].t-g[j].t && best[j]>best[i])
					best[i]=best[j];
			}
			if(best[i]>=0)
				best[i]+=g[i].p;
			if(best[i]>result)
				result=best[i];
		}
		printf("%d\n",result);
	}
	return 0;
}