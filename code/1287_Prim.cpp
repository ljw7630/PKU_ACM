#include <iostream>
using namespace std;
int p,r;
int c[52][52];

int prim(int p)
{
	int i,j,k,sum=0,mini;
	int lowcost[52],closest[52];
	
	for(i=2;i<=p;i++)
	{
		lowcost[i]=c[1][i];
		closest[i]=1;
	}
	closest[1]=0;
	for(i=2;i<=p;i++)
	{
		mini=INT_MAX;
		for(j=2;j<=p;j++)
		{
			if(closest[j]&&lowcost[j]<mini)
			{
				mini=lowcost[j];
				k=j;
			}
		}
		closest[k]=0;
		sum+=mini;

		for(j=2;j<=p;j++)
		{
			if(c[k][j]<lowcost[j]&&closest[j])
			{
				lowcost[j]=c[k][j];
				closest[j]=k;
			}
		}
	}
	return sum;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,x,y,v;
	while(scanf("%d",&p),p!=0)
	{
		scanf("%d",&r);
		for(i=1;i<=p;i++)
			for(j=1;j<=p;j++)
				c[i][j]=INT_MAX;
		for(i=0;i<r;i++)
		{
			scanf("%d%d%d",&x,&y,&v);
			if(c[x][y]>v)
				c[x][y]=c[y][x]=v;
		}
		printf("%d\n",prim(p));
	}
	return 0;
}