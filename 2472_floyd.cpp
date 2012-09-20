#include <iostream>
using namespace std;
int n,m,from,to,p;
double map[105][105];

void floyd()
{
	for(int k=0;k<n;++k)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(map[i][j]<map[i][k]*map[k][j])
					map[i][j]=map[i][k]*map[k][j];
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF&&n)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				map[i][j]=0.0;
		map[0][0]=1.0;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&from,&to,&p);
			map[from-1][to-1]=map[to-1][from-1]=(double)p/100;
		}
		floyd();
		double t=map[0][n-1];
		t*=100;
		printf("%.6lf percent\n",t);
	}
	return 0;
}