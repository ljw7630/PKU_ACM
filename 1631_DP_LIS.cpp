#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,len;
	int a[40002];
	int m[40002];
	int dp[40002];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		dp[0]=0;
		len=-1;
		int res=0;
		for(int i=0;i<n;++i)
		{
			int left=0;
			int right=len;

			while(right>=left)
			{
				int mid=(left+right)/2;
				if(m[mid]<a[i])
					left=mid+1;
				else
					right=mid-1;
			}
			m[left]=a[i];
			if(left>len)
				len++;
			dp[i]=left;

			if(res<dp[i])
				res=dp[i];
		}
		printf("%d\n",res+1);
	}
	return 0;
}