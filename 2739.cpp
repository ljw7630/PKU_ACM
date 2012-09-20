#include <iostream>
using namespace std;
#define n 10002
int a[n],p[n];
void getPrime()
{
	memset(a,0,sizeof(a));
	for(int i=2;i<n;++i)
	{
		if(a[i]==1)
			continue;
		for(int j=2;i*j<n;++j)
		{
			a[i*j]=1;
		}
	}
	int t=0;
	for(int i=2;i<n;++i)
	{
		if(a[i]==0)
			p[t++]=i;
	}
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	getPrime();
	while(scanf("%d",&t)!=EOF&&t!=0)
	{
		int count=0;

		for(int i=0;p[i]<=t;++i)
		{
			int j=i,sum=0;
			while(true)
			{
				sum+=p[j];
				if(sum==t)
				{
					count++;
					break;
				}
				if(sum>t)
					break;
				++j;
			}
		}
		printf("%d\n",count);
	}

	return 0;
}