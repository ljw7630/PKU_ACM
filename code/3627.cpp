#include <iostream>
#include <algorithm>
using namespace std;

int n,b,arr[20005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&b)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		int sum=0,c=n-1;
		while(sum<b)
		{
			sum+=arr[c];
			--c;
		}
		printf("%d\n",n-1-c);
	}
	return 0;
}