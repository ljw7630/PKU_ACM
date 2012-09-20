#include <iostream>
using namespace std;

int c[32005];
int a[32005];
const int maxi=32002;

int lowbit(int t)
{
	return t&(-t);
}

int getSum(int k)
{
	int sum=0;
	for(;k>0;k=k-lowbit(k))
		sum+=c[k];
	return sum;
}

void modify(int k,int delta)
{
	for(;k<maxi;k+=lowbit(k))
		c[k]+=delta;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			a[getSum(++x)]++;
			modify(x,1);
		}
		for(int i=0;i<n;++i)
		{
			printf("%d\n",a[i]);
		}
	}
	return 0;
}