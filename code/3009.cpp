#include <iostream>
using namespace std; 

int w,h,map[22][22],count,countbest;

void dfs(int x,int y)
{
	if(count>=10)
		return;
	if(count>=countbest)
		return;
	for(int i=x+1;i<=h;++i)
	{
		if(i==x+1&&map[i][y]==1)
			break;
		if(map[i][y]==3)
		{
			count++;
			if(count<countbest)
			{
				countbest=count;
			}
			count--;
			return;
		}
		if(map[i][y]==1)
		{
			map[i][y]=0;
			count++;
			dfs(i-1,y);
			count--;
			map[i][y]=1;
			break;
		}
	}
	for(int i=x-1;i>=1;--i)
	{
		if(i==x-1&&map[i][y]==1)
			break;
		if(map[i][y]==3)
		{
			count++;
			if(count<countbest)
			{
				countbest=count;
			}
			count--;
			return;
		}
		if(map[i][y]==1)
		{
			map[i][y]=0;
			count++;
			dfs(i+1,y);
			count--;
			map[i][y]=1;
			break;
		}
	}
	for(int i=y+1;i<=w;++i)
	{
		if(i==y+1&&map[x][i]==1)
			break;
		if(map[x][i]==3)
		{
			count++;
			if(count<countbest)
			{
				countbest=count;
			}
			count--;
			return;
		}
		if(map[x][i]==1)
		{
			map[x][i]=0;
			count++;
			dfs(x,i-1);
			count--;
			map[x][i]=1;
			break;
		}
	}
	for(int i=y-1;i>=1;--i)
	{
		if(i==y-1&&map[x][i]==1)
			break;
		if(map[x][i]==3)
		{
			count++;
			if(count<countbest)
			{
				countbest=count;
			}
			count--;
			return;
		}
		if(map[x][i]==1)
		{
			map[x][i]=0;
			count++;
			dfs(x,i+1);
			count--;
			map[x][i]=1;
			break;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int sx,sy;
	while(scanf("%d%d",&w,&h)!=EOF&&w)
	{
		for(int i=1;i<=h;++i)
		{
			for(int j=1;j<=w;++j)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)
				{
					sx=i,sy=j;
				}
			}
		}
		count=0;
		countbest=INT_MAX;
		dfs(sx,sy);
		if(countbest==INT_MAX)
			printf("-1\n");
		else
			printf("%d\n",countbest);
	}
	return 0;
}