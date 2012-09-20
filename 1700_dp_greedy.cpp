#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n;
	int i;
	int a[1005];
	int dp[1005];
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		dp[0]=0;
		if(n==1)
			printf("%d\n",a[0]);
		else if(n==2)
			printf("%d\n",a[1]);
		else if(n==3)
			printf("%d\n",a[0]+a[1]+a[2]);
		else
		{
			for(i=1;i<n;++i)
			{
				if(i==1)
					dp[i]=dp[i-1]+a[0]+a[i];
				else if(i!=n-1)
					dp[i]=min(dp[i-1]+a[0]+a[i],dp[i-2]+a[i]+2*a[1]+a[0]);
				else
					dp[i]=min(dp[i-1]+a[i],dp[i-2]+a[i]+2*a[1]);
			}
			printf("%d\n",dp[n-1]);
		}
	}
	return 0;
}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	int t,n;
//	int a[1005];
//	int dp[1005];
//	scanf("%d",&t);
//	while(t--)
//	{
//		memset(dp,0,sizeof(dp));
//		scanf("%d",&n);
//		for(int i=1;i<=n;++i)
//			scanf("%d",&a[i]);
//		sort(a+1,a+n+1);
//		int res=0;
//		while(n>3)
//		{
//			int t1=a[n]+a[n-1]+a[1]+a[1];
//			int t2=a[2]+a[2]+a[1]+a[n];
//			res+=min(t1,t2);
//			n-=2;
//		}
//		if(n==3)
//			res+=a[1]+a[2]+a[3];
//		else
//			res+=a[n];
//		printf("%d\n",res);
//	}
//	return 0;
//}