#include <iostream>
using namespace std;

int map[10][10]={0};
int dir[8][2]=
{
	{-1,-2},
	{-2,-1},
	{-2,1},
	{-1,2},
	{1,2},
	{2,1},
	{2,-1},
	{1,-2}
};

struct queue
{
	int x,y;
	int step;
}q[100];

int bfs(int sx,int sy,int ex,int ey)
{
	int head=0,rear=1;
	q[head].x=sx;
	q[head].y=sy;
	q[head].step=0;
	while(head<rear)
	{
		for(int i=0;i<8;++i)
		{
			int nowx=q[head].x+dir[i][0];
			int nowy=q[head].y+dir[i][1];
			if(nowx>=1&&nowx<=8&&nowy>=1&&nowy<=8&&!map[nowx][nowy])
			{
				if(nowx==ex&&nowy==ey)
				{
					return q[head].step+1;
				}
				map[nowx][nowy]=true;
				q[rear].x=nowx;
				q[rear].y=nowy;
				q[rear].step=q[head].step+1;
				rear++;
			}
		}
		head++;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char start[3],end[3];
	while(scanf("%s%s",&start,&end)!=EOF)
	{
		memset(q,0,sizeof(q));
		memset(map,0,sizeof(map));
		int c=0;
		if(strcmp(start,end)==0)
		{
			printf("To get from %s to %s takes 0 knight moves.\n",start,end);
			continue;
		}
		c=bfs(start[0]-'a'+1,start[1]-'0',end[0]-'a'+1,end[1]-'0');
		printf("To get from %s to %s takes %d knight moves.\n",start,end,c);
	}
	return 0;
}