#include <iostream>
using namespace std;
int n,closest[101],edge[101][101];
bool x[101];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
				scanf("%d",&edge[i][j]);
		}
		x[0]=true;
		for(int i=1;i<n;i++)
		{
			closest[i]=0;
			x[i]=false;
		}
		int sum=0,min,t;
		for(int i=0;i<n-1;++i)
		{
			min=INT_MAX;
			for(int j=1;j<n;++j)
			{
				if(edge[j][closest[j]]<min&&!x[j])
				{
					min=edge[j][closest[j]];
					t=j;
				}
			}
			sum+=min;
			x[t]=true;
			for(int k=1;k<n;++k)
			{
				if(edge[k][t]<edge[k][closest[k]]&&!x[k])
				{
					closest[k]=t;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}