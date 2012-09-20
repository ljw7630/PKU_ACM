#include <iostream>
#include <algorithm>
using namespace std;

class MYRECTANGLE
{
public:
	int x1,y1;
	int x2,y2;
}rec[1001];

bool cmp(MYRECTANGLE &a,MYRECTANGLE &b)
{
	if(a.x2==b.x2)
		return a.y2<b.y2;
	else
		return a.x2<b.x2;
}

int n;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d%d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);
		}
		sort(rec,rec+n,cmp);
		int l=rec[0].x2,r=rec[0].y2;
		int res=1;
		for(int i=1;i<n;++i)
		{
			if(rec[i].x1>l&&rec[i].y1>r)
			{
				l=rec[i].x2;
				r=rec[i].y2;
				res++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}