#include <iostream>
#include <algorithm>
using namespace std;
class POINT
{
public:
	int r,c;
	bool friend operator < (POINT a,POINT b)
	{
		if(a.r<b.r)
		{
			return true;
		}
		else if(a.r==b.r&&a.c<b.c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}po[5010];
int R,C,N;
int plant[5010][5010];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,rdis,cdis,rrdis,ccdis,max,len;
	bool flag;
	while(scanf("%d%d",&R,&C)!=EOF)
	{
		memset(po,false,sizeof(po));
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&po[i].r,&po[i].c);
			po[i].r--;
			po[i].c--;
			plant[po[i].r][po[i].c]=true;
		}
		sort(po,po+N);
		max=0;
		for(i=0;i<N;i++)
		{
			for(j=i+1;j<N;j++)
			{
				rdis=po[j].r-po[i].r;
				if(rdis>0&&R-po[i].r<max)
					continue;
				cdis=po[j].c-po[i].c;
				rrdis=po[i].r-rdis;
				ccdis=po[i].c-cdis;
				if(rrdis>=0&&ccdis>=0&&ccdis<C)
					continue;
				rrdis=po[j].r+rdis;
				ccdis=po[j].c+cdis;
				len=2;
				flag=0;
				while(ccdis>=0&&rrdis<R&&ccdis<C)
				{
					if(!plant[rrdis][ccdis])
					{
						flag=true;
						break;
					}
					len++;
					rrdis+=rdis;
					ccdis+=cdis;
				}
				if(len>2&&len>max&&flag==false)
				{
					max=len;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}