#include <iostream>
#include <cmath>
using namespace std;
const int n=1<<15;
int a[n],p[50000];
void create()
{
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	for(int i=2;i<n;++i)
	{
		if(a[i])
			continue;
		for(int j=2;i*j<n;++j)
		{
			a[i*j]=true;
		}
	}
	int c=0;
	for(int i=2;i<n;++i)
	{
		if(!a[i])
			p[c++]=i;
	}
	return;
}

bool isPrime(int x)
{
	int m;
	m=(int)sqrt(float(x));
	for(int i=0;p[i]<(m+1);++i)
		if(x%p[i]==0)
			return false;
	return true;
}
int main()
{
	int k;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	create();
	while(scanf("%d",&k)!=EOF&&k)
	{
		int count=0;
		for(int i=0;p[i]<=k/2;++i)
		{
			if(isPrime(k-p[i]))
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}