#include <iostream>
using namespace std;

struct NODE
{
	int x;
	int y;
	int count;
};

NODE q1[90005],q2[90005];
int map[305][305];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n;
	int direction[8][2]=
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
	scanf("%d",&t);
	while(t--)
	{
		memset(map,0,sizeof(map));
		scanf("%d",&n);
		int head1=0,head2=0;
		scanf("%d%d%d%d",&q1[head1].x,&q1[head1].y,&q2[head2].x,&q2[head2].y);
		q1[head1].count=0;q2[head2].count=0;
		map[q1[head1].x][q1[head1].y]=1;
		map[q2[head2].x][q2[head2].y]=2;
		int rear1=1,rear2=1;
		int s=0;
		bool flag=false;
		if(q1[head1].x==q2[head2].x&&q1[head1].y==q2[head2].y)
		{
			;
		}
		else
		{
			while(true)
			{
				if(head1<rear1)
				{
					for(int i=0;i<8;++i)
					{
						int nowx=q1[head1].x+direction[i][0];
						int nowy=q1[head1].y+direction[i][1];
						if(nowx>=0&&nowx<n&&nowy>=0&&nowy<n)
						{
							if(map[nowx][nowy]&&map[nowx][nowy]%2==0)
							{
								s=1+q1[head1].count+map[nowx][nowy]/2-1;
								flag=true;
								break;
							}
							else if(!map[nowx][nowy])
							{
								map[nowx][nowy]=map[q1[head1].x][q1[head1].y]+2;
								q1[rear1].x=nowx;
								q1[rear1].y=nowy;
								q1[rear1].count=q1[head1].count+1;
								rear1++;
							}
						}
					}
					head1++;
					if(flag)
						break;
				}
				if(head2<rear2)
				{
					for(int i=0;i<8;++i)
					{
						int nowx=q2[head2].x+direction[i][0];
						int nowy=q2[head2].y+direction[i][1];
						if(nowx>=0&&nowx<n&&nowy>=0&&nowy<n)
						{
							if(map[nowx][nowy]&&map[nowx][nowy]%2!=0)
							{
								s=1+q2[head2].count+map[nowx][nowy]/2;
								flag=true;
								break;
							}
							else if(!map[nowx][nowy])
							{
								map[nowx][nowy]=map[q2[head2].x][q2[head2].y]+2;
								q2[rear2].x=nowx;
								q2[rear2].y=nowy;
								q2[rear2].count=q2[head2].count+1;
								rear2++;
							}
						}
					}
					head2++;
					if(flag)
						break;
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}