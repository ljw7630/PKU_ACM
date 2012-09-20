#include <iostream>
using namespace std;
int n,b,h[25],sum;
bool map[20000005];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&b)!=EOF)
	{
		sum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&h[i]);
			sum+=h[i];
		}
		for(int i=1;i<=sum;++i)
			map[i]=false;
		map[0]=true;
		for(int i=0;i<n;++i)
		{
			for(int j=sum;j>=h[i];--j)
				if(map[j-h[i]]==true)
					map[j]=true;
		}
		int t;
		for(t=b;t<=sum;++t)
			if(map[t])
				break;
		printf("%d\n",t-b);
	}
	return 0;
}