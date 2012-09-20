#include <iostream>
#include <algorithm>
using namespace std;
int n;
int lucy,num,a[1002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	int c=0,i;
	while(n--)
	{
		scanf("%d%d",&lucy,&num);
		for(i=0;i<num;i++)
			scanf("%d",&a[i]);
		printf("Scenario #%d:\n",++c);
		sort(a,a+num);
		int sum=0;
		for(i=num-1;i>-1;--i)
		{
			sum+=a[i];
			if(sum>=lucy)
				break;
		}
		if(i>-1)
			printf("%d",num-i);
		else
			printf("impossible");
		printf("\n\n");
	}
	return 0;
}