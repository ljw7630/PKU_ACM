#include <iostream>
#include <algorithm>
using namespace std;

int n,opt[20005];

class doll
{
public:
	int w;
	int h;

	bool friend operator <(doll &a,doll &b)
	{
		if(a.w<b.w)
		{
			return true;
		}
		else if(a.w==b.w&&a.h>b.h)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}d[20005];

int solve()
{
	int count=0,l,r;
	memset(opt,false,sizeof(opt));
	for(int i=0;i<n;++i)
	{
		int temp=d[i].h;
		l=0;
		r=count;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(opt[mid]>=temp)   // 这里保证了opt数组是按h降序的
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		if(count==l)
		{
			count++;
		}
		opt[l]=d[i].h;
	}
	return count;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&d[i].w,&d[i].h);
		}
		sort(d,d+n);
		printf("%d\n",solve());
	}
	return 0;
}