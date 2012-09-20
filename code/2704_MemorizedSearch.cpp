#include <iostream>
using namespace std;

int n;
char map[40][40];
__int64 res[40][40];

__int64 search(int x,int y)
{
	__int64 sum=0;
	if(x==n-1&&y==n-1)
		return 1;
	if(res[x][y]!=0)
		return res[x][y];
	if(x+(map[x][y]-'0')<n&&map[x][y]!='0')
	{
		sum+=search(x+map[x][y]-'0',y);
	}
	if(y+map[x][y]-'0'<n&&map[x][y]!='0')
	{
		sum+=search(x,y+map[x][y]-'0');
	}
	res[x][y]=sum;
	return sum;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n!=-1)
	{
		memset(res,0,sizeof(res));
		for(int i=0;i<n;++i)
			scanf("%s",&map[i]);
		printf("%I64d\n",search(0,0));
	}
	return 0;
}