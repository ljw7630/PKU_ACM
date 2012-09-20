#include <iostream>
using namespace std;

char map[105][105];
bool visit[105][105];
int n,m;
int step[8][2]=
{
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	{0,-1},
};

void floodfill(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]=='@'&&visit[x][y]==false)
	{
		visit[x][y]=true;
		for(int i=0;i<8;++i)
		{
			int xx,yy;
			xx=x+step[i][0];
			yy=y+step[i][1];
			floodfill(xx,yy);
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
	{
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		for(int i=0;i<n;++i)
		{
			scanf("%s",map[i]);
		}
		int count=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(map[i][j]=='@'&&visit[i][j]==false)
				{
					floodfill(i,j);
					++count;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}