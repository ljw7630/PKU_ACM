#include <iostream>
using namespace std;
char truck[2001][8];
int map[2001][2001];
int lowcost[2001];
bool visit[2001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(visit,false,sizeof(visit));
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				map[i][j]=INT_MAX;
		for(int i=0;i<n;++i)
			scanf("%s",truck[i]);
		for(int i=0;i<n-1;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				int c=0;
				for(int k=0;k<7;++k)
				{
					if(truck[i][k]!=truck[j][k])
						++c;
				}
				map[i][j]=map[j][i]=c;
			}
		}
		for(int i=0;i<n;++i)
			lowcost[i]=map[0][i];
		visit[0]=true;
		int count=0;
		for(int i=0;i<n-1;++i)
		{
			int mini=INT_MAX;
			int pos=0;
			for(int j=1;j<n;++j)
			{
				if(!visit[j]&&lowcost[j]<mini)
				{
					mini=lowcost[j];
					pos=j;
				}
			}
			visit[pos]=true;
			count+=mini;
			for(int j=1;j<n;++j)
			{
				if(!visit[j]&&map[pos][j]<lowcost[j])
					lowcost[j]=map[pos][j];
			}
		}
		printf("The highest possible quality is 1/%d.\n",count);
	}
	return 0;
}