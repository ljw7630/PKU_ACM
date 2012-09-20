#include <iostream>
#include <cmath>
using namespace std;
int sum,n,p,t;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		scanf("%d",&p);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&t);
			t=(int)pow((double)t,(double)p);
			if(t>0)
				sum+=t;
		}
		printf("%d\n",sum);
	}
	return 0;
}