#include <iostream>
#include <algorithm>
using namespace std;

class POINT
{
public:
	int x,y;
	bool friend operator <(POINT &a,POINT &b)
	{
		if(a.x==b.x)
			return a.y<b.y;
		else
			return a.x<b.x;
	}
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	POINT arr[50002];
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=0;i<n;++i)
			scanf("%d%d",&arr[i].x,&arr[i].y);
		sort(arr,arr+n);
		int l=arr[n-1].x,r=arr[n-1].y;
		int res=1;
		for(int i=n-2;i>=0;--i)
		{
			if(arr[i].x==l)
			{
				continue;
			}
			else
			{
				if(arr[i].y>r)
				{
					r=arr[i].y;
					l=arr[i].x;
					res++;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}