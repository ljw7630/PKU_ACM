#include <iostream>
using namespace std;

int n,map[15][15],t,index;

void floyd()
{
	for(int k=1;k<=n;++k)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				map[i][j]=min(map[i][j],map[i][k-1]+map[k-1][j]);
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				map[i][j]=65535;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&t);
			map[i][i]=0;
			for(int j=0;j<t;++j)
			{
				scanf("%d",&index);
				scanf("%d",&map[i][index-1]);
			}
		}
		floyd();
		int mini=INT_MAX,maxi=0,node;
		for(int i=0;i<n;++i)
		{
			maxi=0;
			for(int j=0;j<n;++j)
			{
				if(map[i][j]!=0)
				{
					if(maxi<map[i][j])
						maxi=map[i][j];
				}
			}
			if(maxi<mini)
				mini=maxi,node=i;
		}
		if(mini==INT_MAX)
			printf("disjoint\n");
		else
			printf("%d %d\n",node+1,mini);
	}
	return 0;
}