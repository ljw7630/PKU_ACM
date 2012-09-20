#include <iostream>
#include <algorithm>
using namespace std;

int fn,rn,f[11],r[11];
double ans[101];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&fn,&rn)!=EOF&&fn!=0)
	{
		for(int i=0;i<fn;++i)
			scanf("%d",&f[i]);
		for(int i=0;i<rn;++i)
			scanf("%d",&r[i]);
		int c=0;
		for(int i=0;i<fn;++i)
		{
			for(int j=0;j<rn;++j)
			{
				ans[c++]=(double)f[i]/r[j];
			}
		}
		sort(ans,ans+c);
		double t1=0.0,t2=0.0;
		for(int i=1;i<c;++i)
		{
			t1=ans[i]/ans[i-1];
			if(t1>t2)
				t2=t1;
		}
		printf("%.2lf\n",t2);
	}
	return 0;
}
