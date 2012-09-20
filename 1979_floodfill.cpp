#include <iostream>
using namespace std;
int w,h;
char map[220][220];

int floodfill(int x,int y)
{
	int sum=0;
	if(map[x][y]!='#'&&x>=0&&x<h&&y>=0&&y<w)
	{
		map[x][y]='#';
		sum+=floodfill(x-1,y);
		sum+=floodfill(x+1,y);
		sum+=floodfill(x,y-1);
		sum+=floodfill(x,y+1);
		sum++;
		return sum;
	}
	else
	{
		return 0;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,y;
	while(scanf("%d%d",&w,&h)!=EOF&&w)
	{
		int sum=0;
		for(int i=0;i<h;++i)
		{
			scanf("%s",map[i]);
		}
		for(int i=0;i<h;++i)
		{
			for(int j=0;j<w;++j)
			{
				if(map[i][j]=='@')
					x=i,y=j;
			}
		}
		sum=floodfill(x,y);
		printf("%d\n",sum);
	}
	return 0;
}