#include <iostream>
using namespace std;
int n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		int count=0;
		for(int i=1;i<=n;++i)
		{
			int sum=0;
			for(int j=i;j<=n;++j)
			{
				sum+=j;
				if(sum>n)
					break;
				if(sum==n)
				{
					count++;
					break;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}