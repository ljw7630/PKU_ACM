#include <iostream>
using namespace std;

class NODE
{
public:
	int fa;
	int sum;
}mynode[1001];
int map[1001][1001];
bool isvisit[1001][1001];
int n,r;

int dfs(int index,int pre)
{
	int i;
	bool flag=false;
	for(i=1;i<=n;++i)
	{
		if(map[index][i]&&!isvisit[index][i])
		{
			flag=true;
			isvisit[index][i]=isvisit[i][index]=true;
			mynode[i].fa=index;
			mynode[index].sum+=dfs(i,index);
		}
	}
	if(!flag)
	{
		return map[pre][index];
	}
	if(index==r)
		return mynode[r].sum;
	if(map[mynode[index].fa][index]>mynode[index].sum)
	{
		return mynode[index].sum;
	}
	else
	{
		return map[mynode[index].fa][index];
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,y,w;
	while(scanf("%d%d",&n,&r)!=EOF&&n&&r)
	{
		memset(map,0,sizeof(map));
		memset(mynode,0,sizeof(mynode));
		memset(isvisit,false,sizeof(isvisit));
		mynode[r].fa=r;
		mynode[r].sum=0;
		for(int i=0;i<n-1;++i)
		{
			scanf("%d%d%d",&x,&y,&w);
			map[x][y]=w;
			map[y][x]=w;
		}
		int c=dfs(r,r);
		printf("%d\n",c);
	}
	return 0;
}