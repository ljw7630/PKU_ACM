#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n,d;
class POINT
{
public:
	int x;
	int y;
	double start;
	double end;
	bool friend operator <(POINT a,POINT b)
	{
		return a.end<b.end;
	}
}p[1001];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,count=1,ans;
	double t;
	bool flag;
	while(scanf("%d%d",&n,&d)!=EOF&&(n!=0||d!=0))
	{
		flag=true;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			if(p[i].y>d)
				flag=false;
			if(p[i].y<0)
				flag=false;
			t=sqrt((double)d*d-p[i].y*p[i].y);
			p[i].start=p[i].x-t;
			p[i].end=p[i].x+t;
		}
		if(!flag)
		{
			printf("Case %d: -1\n",count);
			count++;
			continue;
		}
		sort(p,p+n);
		for(ans=0,i=0;i<n;ans++,i=j)
		{
			for(j=i+1;j<n;j++)
			{
				if((p[j].x-p[i].end)*(p[j].x-p[i].end)+p[j].y*p[j].y>d*d)
					break;
			}
		}
		printf("Case %d: %d\n",count,ans);
		count++;
	}
	return 0;
}