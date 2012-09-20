#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,h[55];
	int c=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int sum=0,avg;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&h[i]);
			sum+=h[i];
		}
		avg=sum/n;
		sum=0;
		for(int i=0;i<n;++i)
		{
			if(h[i]<avg)
				sum+=avg-h[i];
		}
		printf("Set #%d\n",++c);
		printf("The minimum number of moves is %d.\n\n",sum);
	}
	return 0;
}