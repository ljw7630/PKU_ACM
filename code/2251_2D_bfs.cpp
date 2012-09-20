#include <iostream>
#include <queue>
using namespace std;

const int maxn=35;
char map[maxn][maxn][maxn];
int rec[maxn][maxn][maxn];
int l,r,c;
int dir[6][3]=
{
	{0,1,0},
	{0,0,1},
	{0,-1,0},
	{0,0,-1},
	{1,0,0},
	{-1,0,0}
};

class triple
{
public:
	int x;
	int y;
	int z;
	triple()
	{
	}
	triple(int xx,int yy,int zz)
	{
		x=xx;
		y=yy;
		z=zz;
	}
	bool friend operator == (const triple &a,const triple &b)
	{
		return a.x==b.x&&a.y==b.y&&a.z==b.z;
	}
};

triple s,e;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	queue<triple>qu;
	while(scanf("%d%d%d",&l,&r,&c)!=EOF&&(l+r+c))
	{
		for(int i=0;i<l;++i)
			for(int j=0;j<r;++j)
				for(int k=0;k<c;++k)
					rec[i][j][k]=-1;
		for(int i=0;i<l;++i)
		{
			for(int j=0;j<r;++j)
			{
				scanf("%s",map[i][j]);
				for(int k=0;map[i][j][k];++k)
				{
					if(map[i][j][k]=='S')
						s.x=i,s.y=j,s.z=k;
					else if(map[i][j][k]=='E')
						e.x=i,e.y=j,e.z=k;
				}
			}
		}
		while(!qu.empty())
			qu.pop();
		rec[s.x][s.y][s.z]=0;
		qu.push(s);
		bool flag=false;
		while(!qu.empty())
		{
			triple temp(qu.front());
			qu.pop();
			for(int i=0;i<6;++i)
			{
				int nowx=temp.x+dir[i][0];
				int nowy=temp.y+dir[i][1];
				int nowz=temp.z+dir[i][2];
				if(nowx>=0&&nowx<l&&nowy>=0&&nowy<r&&nowz>=0&&nowz<c&&map[nowx][nowy][nowz]!='#'&&rec[nowx][nowy][nowz]==-1)
				{
					rec[nowx][nowy][nowz]=rec[temp.x][temp.y][temp.z]+1;
					triple newnode(nowx,nowy,nowz);
					if(newnode==e)
					{
						flag=true;
						break;
					}
					qu.push(newnode);
				}
			}
			if(flag)
				break;
		}
		if(flag)
			printf("Escaped in %d minute(s).\n",rec[e.x][e.y][e.z]);
		else
			printf("Trapped!\n");
	}
	return 0;
}