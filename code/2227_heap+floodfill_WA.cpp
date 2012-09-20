#include <iostream>
#include <queue>
using namespace std;

int n,m;
int mymap[301][301];
bool visit[301][301];
int dir[4][2]=
{
	{1,0}
	,{0,1}
	,{-1,0}
	,{0,-1}
};

class mypair
{
public:
	int i;
	int j;
	bool friend operator <(const mypair &a,const mypair &b)
	{
		return mymap[a.i][a.j]>mymap[b.i][b.j];
	}
};

int floodfill(int x,int y,int originvalue)
{
	if(originvalue<mymap[x][y]||x==0||x==m-1||y==0||y==n-1)
		return mymap[x][y];
	int o=mymap[x][y];
	mymap[x][y]=INT_MAX;
	int newx,newy;
	for(int i=0;i<4;++i)
	{
		newx=x+dir[i][0];
		newy=y+dir[i][1];
		if(newx>=0&&newx<m&&newy>=0&&newy<n&&!visit[newx][newy]&&o<=mymap[newx][newy])
		{
			visit[newx][newy]=true;
			mymap[x][y]=min(floodfill(newx,newy,o),mymap[x][y]);
			visit[newx][newy]=false;
		}
		else if(mymap[newx][newy]<o)
		{
			mymap[x][y]=o;
			break;
		}
	}
	int t=mymap[x][y];
	mymap[x][y]=o;
	return t==INT_MAX?o:t;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	__int64 sum;
	mypair p;
	priority_queue<mypair>myheap;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(visit,false,sizeof(visit));
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				scanf("%d",&mymap[i][j]);
				p.i=i,p.j=j;
				myheap.push(p);
			}
		}
		sum=0;
		while(!myheap.empty())
		{
			p=myheap.top();
			myheap.pop();
			if(p.i==0||p.i==m-1||p.j==0||p.j==n-1)
				continue;
			visit[p.i][p.j]=true;
			int o=mymap[p.i][p.j];
			int k=floodfill(p.i,p.j,mymap[p.i][p.j]);
			if(k!=o)
			{
				mymap[p.i][p.j]=k;
				myheap.push(p);
				sum+=k-o;
			}
			visit[p.i][p.j]=false;
		}
		printf("%I64d\n",sum);
	}
	return 0;
}