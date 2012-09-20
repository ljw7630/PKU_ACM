#include <iostream>
#include <algorithm>
using namespace std;
int n,a[10001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i;
	__int64 sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=0;i<n-1;i++)
			sum+=(__int64)(a[i+1]-a[i])*(i+1)*(n-i-1);
		printf("%I64d",sum*2);
	}
	return 0;
}