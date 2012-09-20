#include <iostream>
#include <algorithm>
using namespace std;

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

bool flag[20005];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,i,j,maxh,maxw,res;
	scanf("%d",&t);
	while(t--)
	{
		memset(flag,false,sizeof(flag));
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&d[i].w,&d[i].h);
		}
		sort(d,d+n);
		res=0;
		while(true)
		{
			for(i=0;i<n;++i)
			{
				if(!flag[i])
					break;
			}
			if(i==n)
				break;
			for(j=i+1,flag[i]=true,maxh=d[i].h,maxw=d[i].w;j<n;++j)
			{
				if(d[j].w>maxw&&d[j].h>maxh&&!flag[j])
				{
					flag[j]=true;
					maxw=d[j].w;
					maxh=d[j].h;
				}
			}
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
}