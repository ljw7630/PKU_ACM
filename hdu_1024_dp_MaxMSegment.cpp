#include <iostream>
using namespace std;
const int maxn=1000005;
int a[maxn];
int f[maxn];
int g[maxn];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=0;i<=n;++i)
			f[i]=g[i]=INT_MIN;
		f[0]=g[0]=0;
		for(int i=1;i<=n;++i)
		{
			int t=min(i,m);
			for(int j=1;j<=t;++j)
			{
				f[j]=max(f[j],g[j-1])+a[i];
				g[j-1]=g[j-1]>f[j-1]?g[j-1]:f[j-1];
			}
			g[t]=g[t]>f[t]?g[t]:f[t];
		}
		printf("%d\n",g[m]);
	}
	return 0;
}