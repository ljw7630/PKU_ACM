#include <iostream>
#include <cmath>
using namespace std;
const int n=1000002;
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
	for(int i=3;i<n;++i)
	{
		if(a[i]==0)
			p[t++]=i;
	}
	return;
}

bool isPrime(int k)
{
	int m;
	m=(int)sqrt((float)k);
	for(int i=3;i<m+1;++i)
		if(k%i==0)
			return false;
	return true;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,i;
	getPrime();
	while(scanf("%d",&t)!=EOF&&t)
	{
		bool flag=false;
		for(i=0;p[i]<t;++i)
		{
			if(isPrime(t-p[i]))
			{
				flag=true;
				break;
			}
		}
		if(flag)
			printf("%d = %d + %d\n",t,p[i],t-p[i]);
		else
			printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}