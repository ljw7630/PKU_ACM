#include <iostream>
using namespace std;
int n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int sum1=0;
		int sum2=0;
		for(i=1;;i++)
		{
			sum1+=i*i;
			sum2+=i;
			if(n-sum2==0)
			{	
				break;
			}
			else if(n-sum2<=i+1)
			{
				sum1+=(n-sum2)*(i+1);
				break;
			}
		}
		printf("%d %d\n",n,sum1);
	}
	return 0;
}