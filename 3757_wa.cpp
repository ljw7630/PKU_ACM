#include <iostream>
#include <algorithm>
using namespace std;

struct NODE
{
	double other;
	double cost;
	bool friend operator <(NODE &a,NODE &b)
	{
		if(a.cost<b.cost)
			return true;
		else
			return false;
	}
}node[20005];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,k;
	double f;
	while(scanf("%d%d%lf",&n,&k,&f)!=EOF)
	{
		double p,b,c;
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf%lf",&p,&b,&c);
			node[i].other=(p*b)/(p+b);
			node[i].cost=c;
		}
		sort(node,node+n);
		double sum=0;
		for(int i=0;i<k;++i)
		{
			sum+=node[i].other;
		}
		double res=f/sum;
		sum=0;
		for(int i=0;i<k;++i)
		{
			sum+=(res*node[i].other)*node[i].cost;
		}
		printf("%.4lf\n",sum);
	}
	return 0;
}