#include <iostream>
using namespace std;
int t,c,a[102],p[102],best[102],sum[102];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&c);
		sum[0]=best[0]=0;
		for(i=1;i<=c;i++)
		{
			scanf("%d",&a[i]);
			scanf("%d",&p[i]);
			sum[i]=sum[i-1]+a[i];
			best[i]=INT_MAX;
		}
		for(i=1;i<=c;i++)
		{
			for(j=0;j<i;j++)
			{
				if(best[i]>p[i]*(sum[i]-sum[j]+10)+best[j])
					best[i]=p[i]*(sum[i]-sum[j]+10)+best[j];
			}
		}
		printf("%d\n",best[c]);
	}
	return 0;
}