#include <iostream>
using namespace std;

int n,m,index[305],eachm,map[305][305];

void floyd()
{
	for(int k=0;k<n;++k)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				map[i][j]=0x7ffffff;
		for(int i=0;i<m;++i)
		{
			scanf("%d",&eachm);
			for(int j=0;j<eachm;++j)
			{
				scanf("%d",&index[j]);
			}
			for(int j=1;j<eachm;++j)
			{
				for(int k=0;k<j;++k)
				{
					map[index[k]-1][index[j]-1]=map[index[j]-1][index[k]-1]=1;
				}
			}
		}
		floyd();
		int sum,avg=INT_MAX;
		for(int i=0;i<n;++i)
		{
			sum=0;
			for(int j=0;j<n;++j)
			{
				if(i!=j)
				{
					sum+=map[i][j];
				}
			}
			if(sum<avg)
				avg=sum;
		}
		printf("%d\n",avg*100/(n-1));
	}
	return 0;
}