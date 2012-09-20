#include <iostream>
using namespace std;
int t,len,n,now;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int min,max,e,l;
	scanf("%d",&t);
	while(t--)
	{
		max=min=0;
		scanf("%d%d",&len,&n);
		while(n--)
		{
			scanf("%d",&now);
			if(now<len/2)
			{
				e=now;
				l=len-now;
			}
			else
			{
				e=len-now;
				l=now;
			}
			if(min<e)
				min=e;
			if(max<l)
				max=l;
		}
		printf("%d %d\n",min,max);
	}
	return 0;
}