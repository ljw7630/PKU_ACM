#include <iostream>
using namespace std;
int guest[30];
int n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,sum,part;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&guest[i]);
			sum+=guest[i];
		}
		if(sum%2==1)
		{
			printf("No equal partitioning.\n");
		}
		else
		{
			part=sum/2;
			sum=0;
			for(i=0;i<n;i++)
			{
				sum+=guest[i];
				if(part==sum)
				{
					printf("Sam stops at position %d and Ella stops at position %d.\n",i+1,i+2);
					break;
				}
				if(part<sum)
				{
					printf("No equal partitioning.\n");
					break;
				}
			}
		}
	}
	return 0;
}