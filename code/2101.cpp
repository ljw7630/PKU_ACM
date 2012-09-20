#include <iostream>
#include <cmath>
using namespace std;
int n,e;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a,b,t;
	while(scanf("%d%d",&n,&e)==2)
	{
		a=b=0;
		for(int i=0;i<n-1;++i)
		{
			scanf("%d",&t);
			a+=t;
		}
		for(int i=0;i<e-1;++i)
		{
			scanf("%d",&t);
			b+=t;
		}
		printf("%d\n",(int)ceil(sqrt((double)(a*a+b*b))));
	}
	return 0;
}