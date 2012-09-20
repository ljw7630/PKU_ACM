#include <iostream>
using namespace std;
int n,colsum[101][101],matrix[101][101];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,cursum,sum,maxsub;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&matrix[i][j]);
	memset(colsum,0,sizeof(colsum));
	maxsub=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n+1;j++)
		{
			cursum=0;
			sum=0;
			for(k=0;k<n;k++)
			{
				colsum[k][j]=colsum[k][j-1]+matrix[k][j-1];
				sum+=colsum[k][j]-colsum[k][i];
				if(sum<0)
					sum=0;
				if(sum>cursum)
					cursum=sum;
			}
			if(cursum>maxsub)
				maxsub=cursum;
		}
	}
	printf("%d\n",maxsub);
	return 0;
}