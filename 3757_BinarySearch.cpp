//vi*t=fi -> vi=(pi*bi)/(pi+bi)
//fi/t=vi -> F/t=sigma(vi)
//cost=sigma(ci*fi)=sigma(t*vi*ci) and t*vi=fi
//let xi=vi*ci, so cost=sigma(xi*t)=F*sigma(xi)/sigma(vi)
//so y=sigma(cost*vi-F*xi)=0; assume s=cost*vi-F*xi
//enumerate cost binarily, sort the s and add front k s
//if the sum greater than 0, then is greater else is less than

#include <iostream>
#include <algorithm>
using namespace std;

const double eps=1e-6;

struct server
{
	double v;
	double s;
	double c;
	bool friend operator <(server &x,server &y)
	{
		if(x.s<y.s)
			return true;
		else
			return false;
	}
}a[20005];

double myabs(double x)
{
	if(x>0)
		return x;
	else
		return -x;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,k;
	double f;
	double p,b,c;
	while(scanf("%d%d%lf",&n,&k,&f)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf%lf",&p,&b,&c);
			a[i].v=(p*b)/(p+b);
			a[i].c=c;
		}
		double l=-1,r=100000000000,mid;
		while(myabs(r-l)>eps)
		{
			mid=(l+r)/2;
			for(int i=0;i<n;++i)
				a[i].s=a[i].v*(a[i].c-mid/f);
			sort(a,a+n);
			double sum=0;
			for(int i=0;i<k;++i)
				sum+=a[i].s;
			if(sum>=0)
				l=mid;
			else
				r=mid;
		}
		printf("%.4lf\n",mid);
	}
	return 0;
}