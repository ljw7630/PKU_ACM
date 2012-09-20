#include <iostream>
using namespace std;

__int64 sum,len[10001],low,num1,high,mid;
int n,k,count,num2;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%I64d.%d\n",&num1,&num2);
			len[i]=num1*100+num2;
			sum+=len[i];
		}
		low=0;high=sum;
		while(low+1<high)
		{
			count=0;
			mid=(low+high)/2;
			for(i=0;i<n;i++)
				count+=(len[i]/mid);
			if(count>=k)
			{
				low=mid;
			}
			else
			{
				high=mid;
			}
			if(low==high)
				break;
		}
		if(low<1)
		{
			printf("0.00\n");	
		}
		else
		{
			printf("%.2lf\n",(double)low/100.0);
		}
	}
	return 0;
}