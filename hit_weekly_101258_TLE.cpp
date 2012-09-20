//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int t,n,sum,mycount;
//bool flag;
//int arr[500005];
//bool check[500005];
//
//void dfs(int index)
//{
//	if(index==n)
//		return;
//	for(int i=index;i<n;++i)
//	{
//		if(sum+arr[i]<=47)
//		{
//			sum+=arr[i];
//			check[i]=true;
//			if(sum==47)
//			{
//				mycount++;
//			}
//			else
//			{
//				dfs(i+1);
//			}
//			sum-=arr[i];
//			check[i]=false;
//		}
//		else
//		{
//			return;
//		}
//		if(i>0&&arr[i]==arr[i-1]&&arr[i]<47)
//			i++;
//	}
//}
//
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	scanf("%d",&t);
//	int maxi;
//	while(t--)
//	{
//		scanf("%d",&n);
//		sum=0;
//		for(int i=0;i<n;++i)
//		{
//			check[i]=false;
//			scanf("%d",&arr[i]);
//		}
//		sort(arr,arr+n);
//		sum=0;
//		mycount=0;
//		flag=true;
//		dfs(0);
//		printf("%d\n",mycount);
//	}
//}

#include <algorithm>
using namespace std;

int t,n;
int arr[500001];
int add[500001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		add[0]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&arr[i]);
			add[i]=add[i-1]+arr[i];
		}
		int sum;
		int c=0;
		for(int i=0;i<n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(add[j]-add[i]==47)
					c++;
			}
		}
		printf("%d\n",c);
	}
	return 0;
}