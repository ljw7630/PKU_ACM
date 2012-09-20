#include <iostream>
#include <cmath>
using namespace std;

int l1,l2,l3,n;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		int mini=INT_MAX;
		for(int i=1;i<=sqrt((double)n)+1;++i)
		{
			if(n%i==0)
			{
				for(int j=1;j<=n/i;++j)
				{
					int k=i*j;
					if(n%k==0)
					{
						k=n/k;
						if(mini>(i*j+j*k+i*k))
						{
							mini=i*j+j*k+i*k;
							l1=i,l2=j,l3=k;
						}
					}
				}
			}
		}
		printf("%d %d %d\n",l1,l2,l3);
	}
}