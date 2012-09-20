#include <iostream>
using namespace std;
int N,n;
int arr[1005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int c=1,sum;
	scanf("%d",&N);
	arr[1]=1;
	for(int i=2;i<=1002;++i)
		arr[i]+=arr[i-1]+i;
	while(N--)
	{
		sum=0;
		printf("%d ",c++);
		scanf("%d",&n);
		printf("%d ",n);
		for(int i=1;i<=n;++i)
			sum+=arr[i+1]*i;
		printf("%d\n",sum);
	}
	return 0;
}