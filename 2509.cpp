#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);	
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		int count=0,t;
		while(n>=k)
		{
			t=n/k;
			count+=t*k;
			n=n%k+t;
		}
		count+=n;
		printf("%d\n",count);
	}
	return 0;
}