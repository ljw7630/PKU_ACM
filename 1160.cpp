#include <iostream>
using namespace std;
int v,p,lensum[35][310],cost[310][310],dist[310];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,m;
	while(scanf("%d%d",&v,&p)!=EOF)
	{
		for(i=1;i<=v;i++)
			scanf("%d",&dist[i]);
		for(i=1;i<=v;i++)
			for(j=1;j<=v;j++)
			{
				cost[i][j]=0;
				m=(i+j)/2;
				for(k=i;k<=j;k++)
				{
					cost[i][j]+=(dist[m]-dist[k])>=0?(dist[m]-dist[k]):(dist[k]-dist[m]);
				}
			}
		memset(lensum,30000,sizeof(lensum));
		for(j=1;j<=v;j++)
			lensum[1][j]=cost[1][j];
		for(i=1;i<p;i++)
			for(j=1;j<=v;j++)
			{
				if(lensum[i][j]<INT_MAX)
				{
					for(k=1;j+k<=m;k++)
					{
						if(lensum[i+1][j+k]>lensum[i][j]+cost[j+1][j+k])
						{
							lensum[i+1][j+k]=lensum[i][j]+cost[j+1][j+k];
						}
					}
				}
			}
		printf("%d\n",lensum[p][v]);
	}
	return 0;
}