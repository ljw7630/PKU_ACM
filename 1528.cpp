#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d",&n)!=EOF&&n)
	{
		int sum=0;
		for(int i=1;i<=n/2;++i)
			if(n%i==0)
				sum+=i;
		printf("%5d  ",n);
		if(sum==n)
			printf("PERFECT\n");
		else if(sum<n)
			printf("DEFICIENT\n");
		else
			printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}