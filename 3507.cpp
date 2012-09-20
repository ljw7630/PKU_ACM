#include <iostream>
using namespace std;
int arr[10];
int mini,maxi,sum;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(true)
	{
		mini=INT_MAX;
		maxi=0;
		sum=0;
		for(int i=0;i<6;++i)
		{
			scanf("%d",&arr[i]);
			if(arr[i]<mini)
				mini=arr[i];
			if(arr[i]>maxi)
				maxi=arr[i];
			sum+=arr[i];
		}
		if(sum==0)
			break;
		printf("%g\n",(double)(sum-mini-maxi)/4);
	}
	return 0;
}