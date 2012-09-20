#include <iostream>
using namespace std;

int n,k,t;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		int sum=0;
		scanf("%d",&k);
		for(int i=0;i<k;++i)
		{
			scanf("%d",&t);
			sum+=t;
		}
		printf("%d\n",sum-k+1);
	}
	return 0;
}