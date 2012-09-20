#include <iostream>
using namespace std;

int n,p,q,count,calpath,sum;
bool map[27][27];
bool flag;
struct point
{
	int x,y;
}path[700];
int direction[8][2]=
{
	{-2,-1},
	{-2,1},
	{-1,-2},
	{-1,2},
	{1,-2},
	{1,2},
	{2,-1},
	{2,1}
};

void printout()
{
	for(int i=1;i<calpath;++i)
	{
		printf("%c%d",path[i].x-1+'A',path[i].y);
	}
	printf("\n");
}

bool check()
{
	for(int i=1;i<=p;++i)
	{
		for(int j=1;j<=q;++j)
		{
			if(!map[i][j])
				return false;
		}
	}
	return true;
}

void dfs(int row,int col)
{
	if(flag)
		return;
	if(count==sum)
	{
		if(check())
		{
			flag=true;
			return;
		}
		else
		{
			return;
		}
	}
	int nextrow,nextcol;
	for(int i=0;i<8;++i)
	{
		nextrow=row+direction[i][0];
		nextcol=col+direction[i][1];
		if(nextrow>=1&&nextrow<=p&&nextcol>=1&&nextcol<=q&&map[nextrow][nextcol]==false)
		{
			map[nextrow][nextcol]=true;
			path[calpath].x=nextrow;
			path[calpath].y=nextcol;
			calpath++;
			count++;
			dfs(nextrow,nextcol);
			if(flag)
				return;
			count--;
			calpath--;
			map[nextrow][nextcol]=false;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		flag=false;
		count=1;
		calpath=1;
		memset(map,false,sizeof(map));
		scanf("%d%d",&q,&p);
		sum=p*q;
		path[calpath].x=path[calpath].y=1;
		calpath++;
		map[1][1]=true;
		dfs(1,1);
		printf("Scenario #%d:\n",i);
		if(flag)
		{
			printout();
		}
		else
			printf("impossible\n");
		printf("\n");
	}
	return 0;
}