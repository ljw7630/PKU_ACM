// TLE binary index tree

//#include <iostream>
//using namespace std;
//
//int n,s;
//int tree[20005];
//int arr[20005];
//int lowbit[20005];
//
//void update(int index)
//{
//	while(index<s)
//	{
//		tree[index]++;
//		index+=lowbit[index];
//	}
//}
//
//int getrank(int index)
//{
//	int sum=0;
//	while(index>0)
//	{
//		sum+=tree[index];
//		index-=lowbit[index];
//	}
//	return sum;
//}
//
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	for(int i=0;i<20005;++i)
//		lowbit[i]=i&(-i);
//	while(scanf("%d%d",&n,&s)!=EOF)
//	{
//		memset(tree,0,sizeof(tree));
//		int sum=0;
//		for(int i=0;i<n;++i)
//		{
//			scanf("%d",&arr[i]);
//			if(arr[i]>=s)
//				continue;
//			sum+=getrank(s-arr[i]);
//			update(arr[i]);
//		}
//		printf("%d\n",sum);
//	}
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	int n,s;
//	int arr[20005];
//	while(scanf("%d%d",&n,&s)!=EOF)
//	{
//		for(int i=0;i<n;++i)
//		{
//			scanf("%d",&arr[i]);
//		}
//		sort(arr,arr+n);
//		int count=0;
//		int j=n-1;
//		for(int i=0;i<n;++i)
//		{
//			if(arr[i]>=s)
//				break;
//			while(arr[i]+arr[j]>s)
//				j--;
//			if(j<=i)
//				break;
//			count+=(j-i);
//		}
//		printf("%d\n",count);
//	}
//}