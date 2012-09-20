#include <iostream>
using namespace std;

int row,col;
int sum;
int direction[8][2]=
{
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	{0,-1},
	{-1,-1}
};
bool map[21][21];
bool isVisit[21][21];

void dfs(int x,int y)
{
	int posx,posy;
	isVisit[x][y]=true;
	for(int i=0;i<8;++i)
	{
		posx=x+direction[i][0];
		posy=y+direction[i][1];
		if(posx>=1&&posx<=row&&posy>=1&&posy<=col)
		{
			if(map[posx][posy]==true&&isVisit[posx][posy]==false)
			{
				dfs(posx,posy);
			}
			else if(map[posx][posy]==false&&(posx==x||posy==y))
			{
				sum++;
			}
		}
		else if(posx==x||posy==y)
			sum++;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char temp;
	int rclick,cclick;
	while(scanf("%d%d%d%d",&row,&col,&rclick,&cclick)!=EOF)
	{
		if(row+col+rclick+cclick==0)
			break;
		for(int i=1;i<=row;++i)
		{
			getchar();
			for(int j=1;j<=col;++j)
			{
				scanf("%c",&temp);
				if(temp=='.')
					map[i][j]=false,isVisit[i][j]=false;
				else
					map[i][j]=true,isVisit[i][j]=false;
			}
		}
		sum=0;
		dfs(rclick,cclick);
		printf("%d\n",sum);
	}
	return 0;
}
