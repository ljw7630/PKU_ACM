#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double grid1[202],grid2[202],l1[101],l2[101],r1[101],r2[101];
	int n,ccount=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int c=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf%lf%lf",&l1[i],&r1[i],&l2[i],&r2[i]);
			grid1[c]=l1[i];
			grid2[c++]=r1[i];
			grid1[c]=l2[i];
			grid2[c++]=r2[i];
		}
		sort(grid1,grid1+c);
		sort(grid2,grid2+c);
		double sum=0;
		for(int i=0;i<c-1;++i)
		{
			for(int j=0;j<c-1;++j)
			{
				for(int k=0;k<n;++k)
				{
					if(grid1[i]>=l1[k]&&grid2[j]>=r1[k]&&grid1[i+1]<=l2[k]&&grid2[j+1]<=r2[k])
					{
						sum+=(grid1[i+1]-grid1[i])*(grid2[j+1]-grid2[j]);
						break;
					}
				}
			}
		}
		printf("Test case #%d\n",++ccount);
		printf("Total explored area: %.2lf\n\n",sum);
	}
	return 0;
}