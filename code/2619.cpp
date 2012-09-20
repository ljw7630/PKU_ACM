#include <iostream>
using namespace std;
int n,k,s,t,r;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&k)==2)
	{
		int temp=n;
		while(k--)
		{
			int count=0;
			n=temp;
			scanf("%d%d%d",&s,&t,&r);
			while(1)
			{
				if(s*t>=n)
				{
					if(n%s==0)
						count+=n/s;
					else
						count+=n/s+1;
					printf("%d\n",count);
					break;
				}
				else
				{
					n-=s*t;
					count+=t+r;
				}
			}
		}
	}
	return 0;
}