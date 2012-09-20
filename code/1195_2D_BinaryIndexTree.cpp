#include <iostream>
using namespace std;

int maxn;
int tree[1035][1035];
int lowbit[1035];

void update(int xx,int yy,int inc)
{
	int yt;
	while(xx<=maxn)
	{
		yt=yy;
		while(yt<=maxn)
		{
			tree[xx][yt]+=inc;
			yt+=lowbit[yt];
		}
		xx+=lowbit[xx];
	}
}

int getrank(int x,int y)
{
	int sum=0,yt;
	while(x>0)
	{
		yt=y;
		while(yt>0)
		{
			sum+=tree[x][yt];
			yt-=lowbit[yt];
		}
		x-=lowbit[x];
	}
	return sum;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(int i=0;i<1035;++i)
		lowbit[i]=i&(-i);
	int command,s,x,y,c,l,r,b,t,sum=0;
	while(scanf("%d",&command)!=EOF&&command!=3)
	{
		switch(command)
		{
		case 0:
			scanf("%d",&s);
			memset(tree,0,sizeof(tree));
			for(maxn=1;maxn<s;maxn<<=1)
				;
			break;
		case 1:
			scanf("%d%d%d",&x,&y,&c);
			x++,y++;
			update(x,y,c);
			break;
		case 2:
			scanf("%d%d%d%d",&l,&b,&r,&t);
			sum=getrank(r+1,t+1)-getrank(r+1,b)-getrank(l,t+1)+getrank(l,b);
			printf("%d\n",sum);
			break;
		default:
			break;
		}
	}
}