#include <iostream>
using namespace std;

int n;
double maxi;
double arr[1005];

void LCS(int b[],bool flag)
{
	if(flag)
	{
		for(int i=0;i<n;++i)
		{
			b[i]=1;
		}
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				if(arr[i]<arr[j]&&b[j]<b[i]+1)
					b[j]=b[i]+1;
			}
		}
	}
	else
	{
		for(int i=0;i<n;++i)
		{
			b[i]=1;
		}
		for(int i=n-1;i>-1;--i)
		{
			for(int j=i-1;j>-1;--j)
			{
				if(arr[i]<arr[j]&&b[j]<b[i]+1)
					b[j]=b[i]+1;
			}
		}		
	}
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int rank1[1005],rank2[1005];
	while(scanf("%d",&n)!=EOF)
	{
		maxi=0.0;
		for(int i=0;i<n;++i)
		{
			scanf("%lf",&arr[i]);
			if(arr[i]>maxi)
				maxi=arr[i];
		}
		LCS(rank1,true);
		LCS(rank2,false);
		int themax=0;
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				if(rank1[i]+rank2[j]>themax)
					themax=rank1[i]+rank2[j];
			}
		}
		printf("%d\n",n-themax);
	}
	return 0;
}