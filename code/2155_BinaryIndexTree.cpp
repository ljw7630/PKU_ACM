#include <iostream>
using namespace std;

bool map[1005][1005];
int lowbit[1005];
const int maxn=1002;

void update(int x,int y)
{
	while(x>0)
	{
		int yt=y;
		while(yt>0)
		{
			map[x][yt]=!map[x][yt];
			yt-=lowbit[yt];
		}
		x-=lowbit[x];
	}
};

int getrank(int x,int y)
{
	int res=0;
	while(x<=maxn)
	{
		int yt=y;
		while(yt<=maxn)
		{
			res^=map[x][yt];
			yt+=lowbit[yt];
		}
		x+=lowbit[x];
	}
	return res;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(int i=0;i<1005;++i)
		lowbit[i]=i&(-i);
	int t,n,m;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		memset(map,false,sizeof(map));
		scanf("%d%d",&n,&m);
		while(m--)
		{
			cin >> ch;
			if(ch=='C')
			{
				int x1,x2,y1,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				update(x2,y2);
				update(x2,y1-1);
				update(x1-1,y2);
				update(x1-1,y1-1);
			}
			else if(ch=='Q')
			{
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",getrank(x,y));
			}
		}
		printf("\n");
	}
	return 0;
}