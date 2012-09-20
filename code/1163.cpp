#include <iostream>
using namespace std;
int n,arr[101][101],sum[101][101];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,a,b,c;
	while(scanf("%d",&n)!=EOF)
	{
		memset(sum,0,sizeof(sum));
		memset(arr,0,sizeof(arr));
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		for(j=0;j<n;j++)
		{
			sum[n-1][j]=arr[n-1][j];
		}
		for(i=n-2;i>=0;i--)
		{
			for(j=0;j<=i;j++)
			{
				a=arr[i][j]+sum[i+1][j];
				b=arr[i][j]+sum[i+1][j+1];
				sum[i][j]=a>b?a:b;
			}
		}
		printf("%d\n",sum[0][0]);
	}
	return 0;
}