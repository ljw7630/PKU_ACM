#include <iostream>
using namespace std;

int n,m;
int map[1005][1005];
int longest[1005];
bool x[1005];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(map[a][b]<c)
			{
				map[a][b]=c;
				map[b][a]=c;
			}
		}
		for(int i=2;i<=n;++i)
		{
			longest[i]=1;
			x[i]=false;
		}
		x[1]=true;
		int sum=0;
		bool flag=true;
		for(int i=1;i<n;++i)
		{
			int maxi=0;
			int pos=1;
			for(int j=2;j<=n;++j)
			{
				if(maxi<map[j][longest[j]]&&!x[j])
				{
					maxi=map[j][longest[j]];
					pos=j;
				}
			}
			if(maxi==0)
			{
				flag=false;
			}
			else
			{
				sum+=maxi;
			}
			x[pos]=true;
			for(int k=2;k<=n;++k)
			{
				if(map[k][longest[k]]<map[k][pos]&&!x[k])
				{
					longest[k]=pos;
				}
			}
		}
		if(flag)
			printf("%d\n",sum);
		else
			printf("-1\n");
	}
	return 0;
}