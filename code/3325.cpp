#include <iostream>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int n;
	int arr[101];
	while(scanf("%d",&n)!=EOF&&n)
	{
		int maxi=0,mini=INT_MAX;
		int sum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&arr[i]);
			if(arr[i]>maxi)
				maxi=arr[i];
			if(arr[i]<mini)
				mini=arr[i];
			sum+=arr[i];
		}
		printf("%d\n",(sum-maxi-mini)/(n-2));
	}
	return 0;
}