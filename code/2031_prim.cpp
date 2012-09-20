#include <iostream>
#include <cmath>
using namespace std;
const double eps=1e-6;
const double maxn=1e9;
struct PT
{
	double x;
	double y;
	double z;
	double r;
	double cal(PT &other)
	{
		double res=sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y)+(z-other.z)*(z-other.z));
		res=res-r-other.r;
		if(res<eps)
			res=0.0;
		return res;
	}
};
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	PT p[105];
	double lowcost[105];
	double map[105][105];
	bool in[105];
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				map[i][j]=maxn;
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z,&p[i].r);
		}
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				map[i][j]=map[j][i]=p[i].cal(p[j]);
			}
		}
		for(int i=1;i<n;++i)
		{
			lowcost[i]=map[0][i];
			in[i]=false;
		}
		in[0]=true;
		int pos;
		double sum=0.0;
		for(int i=1;i<n;++i)
		{
			double mini=maxn;
			for(int j=1;j<n;++j)
			{
				if(!in[j]&&mini>lowcost[j])
				{
					mini=lowcost[j];
					pos=j;
				}
			}
			in[pos]=true;
			sum+=mini;
			for(int j=1;j<n;++j)
			{
				if(!in[j]&&map[pos][j]<lowcost[j])
					lowcost[j]=map[pos][j];
			}
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}
