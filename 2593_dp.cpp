#include <iostream>
using namespace std;

int n;
int arr[100002];
int sum1[100002];
int sum2[100002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&arr[i]);
		int temp=0;
		int sum=INT_MIN;
		for(int i=0;i<n;++i)
		{
			if(temp>0)   // this is important.
				temp+=arr[i];
			else
				temp=arr[i];
			if(sum<temp)
				sum=temp;
			sum1[i]=sum;
		}
		temp=0;
		sum=INT_MIN;
		for(int i=n-1;i>=0;--i)
		{
			if(temp>0)
				temp+=arr[i];
			else
				temp=arr[i];
			if(sum<temp)
				sum=temp;
			sum2[i]=sum;
		}
		sum=INT_MIN;
		for(int i=1;i<n;++i)
		{
			if(sum1[i-1]+sum2[i]>sum)
				sum=sum1[i-1]+sum2[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
