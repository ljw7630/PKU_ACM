#include <iostream>
using namespace std;

struct rectangle
{
	int l,h,r;
}rec[10];

bool flag[10];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int besth,stop,ep,sp;
	stop=0;
	for(int i=1;i<=8;++i)
	{
		scanf("%d%d%d",&rec[i].l,&rec[i].h,&rec[i].r);
		if(stop<rec[i].r);
			stop=rec[i].r;
	}
	int nowindex;
	int index=1;
	nowindex=index;
	sp=rec[index].l;
	ep=rec[index].l;
	besth=rec[index].h;
	while(ep<stop)
	{
		ep++;
		if(ep>=rec[index].r)
		{
			flag[index]=true;
			printf("%d %d ",sp,besth);
			besth=0;
			int i,cur;
			bool flag2=false;
			for(i=nowindex;i>0;--i)
			{
				if(!flag[i]&&besth<rec[i].h&&rec[i].r>ep)
				{
					besth=rec[i].h;
					sp=ep;
					flag2=true;
					cur=i;
				}
			}
			if(!flag2)
			{
				printf("%d 0 ",ep);
				nowindex++;
				sp=rec[nowindex].l;
				ep=sp;
				besth=rec[nowindex].h;
				index=nowindex;		
			}
			else
			{
				sp=ep;
				besth=rec[cur].h;
				index=cur;
			}
		}
		else if(ep<rec[nowindex+1].l&&nowindex<8)
		{
			continue;
		}
		else if(rec[nowindex+1].h<rec[index].h&&nowindex<8)
		{
			nowindex++;
			continue;
		}
		else if(nowindex<8)
		{
			nowindex++;
			printf("%d %d ",sp,besth);
			sp=ep;
			besth=rec[nowindex].h;
			index=nowindex;
		}
	}
	printf("%d 0 ",rec[index].r);

	return 0;
}