#include <iostream>
#include <queue>
using namespace std;
int mymap[301][301];
int dir[4][2]=
{
	{1,0}
	,{0,1}
	,{-1,0}
	,{0,-1}
};

class PAIR
{
public:
	PAIR()
	{
	
	}
	PAIR(int x,int y)
	{
		i=x;
		j=y;
	}
	int i;
	int j;

	bool friend operator <(const PAIR &a,const PAIR &b)
	{
		return mymap[a.i][a.j]>mymap[b.i][b.j];
	}
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m;
	bool visit[301][301];
	priority_queue<PAIR> pq;
	PAIR t;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(visit,false,sizeof(visit));
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&mymap[i][j]);
		for(int i=0;i<m;++i)
		{
			t.i=i,t.j=0;
			visit[i][0]=true;
			pq.push(t);
			t.i=i,t.j=n-1;
			visit[i][n-1]=true;
			pq.push(t);
		}
		for(int j=1;j<n-1;++j)
		{
			t.i=0,t.j=j;
			visit[0][j]=true;
			pq.push(t);
			t.i=m-1,t.j=j;
			visit[m-1][j]=true;
			pq.push(t);
		}
		int newx,newy;
		int x,y;
		int sum=0;
		while(!pq.empty())
		{
			t=pq.top();pq.pop();
			x=t.i;
			y=t.j;
			for(int i=0;i<4;++i)
			{
				newx=x+dir[i][0];
				newy=y+dir[i][1];
				if(newx>=0&&newx<m&&newy>=0&&newy<n&&!visit[newx][newy])
				{
					visit[newx][newy]=true;
					if(mymap[x][y]>mymap[newx][newy])
					{
						sum+=mymap[x][y]-mymap[newx][newy];
						mymap[newx][newy]=mymap[x][y];
					}
					t.i=newx,t.j=newy;
					pq.push(t);
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}