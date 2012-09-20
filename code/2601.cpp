#include <iostream>
using namespace std;
int n;
double a0,a1,anp1,c[3002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		c[0]=0;
		scanf("%lf%lf",&a0,&anp1);
		for(int i=1;i<=n;++i)
		{
			scanf("%lf",&c[i]);
			c[i]+=c[i-1];
		}
		a1=anp1+n*a0;
		for(int i=1;i<=n;++i)
			a1-=2*c[i];
		printf("%.2lf\n",a1/(n+1));
	}
	return 0;
}