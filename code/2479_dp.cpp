#include <iostream>
using namespace std;
const int num=50005;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n;
	int arr[num];
	int sum1[num];
	int sum2[num];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&arr[i]);
		int temp=0;
		int sum=INT_MIN;
		for(int i=0;i<n;++i)
		{
			if(temp>0)
				temp+=arr[i];
			else
				temp=arr[i];
			if(sum<temp)
				sum=temp;
			sum1[i]=sum;
		}
		temp=0;
		sum=INT_MIN;
		for(int i=n-1;i>-1;--i)
		{
			if(temp>0)
				temp+=arr[i];
			else
				temp=arr[i];
			if(sum<temp)
				sum=temp;
			sum2[i]=sum;
		}
		int res=INT_MIN;
		for(int i=1;i<n;++i)
		{
			if(res<sum1[i-1]+sum2[i])
				res=sum1[i-1]+sum2[i];
		}
		printf("%d\n",res);
	}
	return 0;
}