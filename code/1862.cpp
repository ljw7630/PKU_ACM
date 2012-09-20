#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
double a[10001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i;
	double t;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%lf",&a[i]);
		sort(a,a+n);
		while(n!=1)
		{
			t=2*sqrt(a[n-1]*a[n-2]);
			n--;
			a[n-1]=t;
		}
		printf("%.3lf\n",a[0]);
	}
	return 0;
}