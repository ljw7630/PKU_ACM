#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m,sum,k,i,j;
	while(cin>>n>>m)
	{
		if(n==-1||m==-1)
			break;
		sum=0;
		for(i=n;i>=1;--i)
		{
			sum+=(n-i);
			if(sum>=m)
				break;
		}
		for(j=1;j<i;++j)
			printf("%d ",j);
		int k=(m+i)-(n-i)*(n-i-1)/2;
		printf("%d",k);
		for(j=n;j>=i;--j)
		{
			if(j!=k)
				printf(" %d",j);
		}
		printf("\n");
	}
	return 0;
}