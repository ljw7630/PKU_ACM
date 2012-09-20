#include <iostream>
using namespace std;

int r,c;

int dir[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

struct queue
{
	int posx;
	int posy;
	int flag;
	int step;
}q[200005];

char str[25][25];

bool inrange(int x,int y)
{
	if(x>=0&&x<r&&y>=0&&y<c)
		return true;
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int head,rear,nowx,nowy;
	scanf("%d%d",&r,&c);
	int maxstep=1;
	for(int i=0;i<r;++i)
	{
		scanf("%s",str[i]);
	}
	q[0].posx=0;
	q[0].posy=0;
	q[0].flag=(1<<(int)(str[0][0]-'A'));
	q[0].step=1;
	head=0;
	rear=1;
	while(head<rear)
	{
		for(int i=0;i<4;++i)
		{
			nowx=q[head].posx+dir[i][0];
			nowy=q[head].posy+dir[i][1];
			if(inrange(nowx,nowy)&&(q[head].flag&(1<<(int)(str[nowx][nowy]-'A')))==0)
			{
				q[rear].posx=nowx;
				q[rear].posy=nowy;
				q[rear].flag=q[head].flag+(1<<(int)(str[nowx][nowy]-'A'));
				q[rear].step=q[head].step+1;
				if(maxstep<q[rear].step)
					maxstep=q[rear].step;
				rear++;
			}
		}
		head++;
	}
	printf("%d\n",maxstep);
	return 0;
}