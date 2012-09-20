#include <iostream>
using namespace std;

int m,ver,hor;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int v,h,nowv,nowh;
	while(scanf("%d",&m)!=EOF&&m)
	{
		ver=0;hor=0;
		nowv=0;nowh=0;
		while(true)
		{
			scanf("%d%d",&v,&h);
			if(v==-1||h==-1)
				break;
			if(nowv+v<=m)
			{
				nowv+=v;
				if(nowv>ver)
					ver=nowv;
				if(h>nowh)
				{
					nowh=h;
				}
			}
			else
			{
				nowv=v;
				if(nowv>ver)
					ver=nowv;
				hor+=nowh;
				nowh=h;
			}
		}
		printf("%d x %d\n",ver,nowh+hor);
	}
	return 0;
}