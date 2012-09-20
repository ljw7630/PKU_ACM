#include <iostream>
using namespace std;
struct node
{
	int l;
	int r;
	int len;
}a[2*10005];

void createTree(int l,int r,int index)
{
	a[index].l=l;
	a[index].r=r;
	a[index].len=r-l+1;
	if(l==r)
		return;
	else
	{
		int mid=(l+r)/2;
		createTree(l,mid,2*index);
		createTree(mid+1,r,2*index+1);
	}
}

int order(int index,int n)
{
	a[index].len--;
	if(a[index].l==a[index].r)
		return a[index].l;
	else if(a[2*index].len>=n)
		return order(2*index,n);
	else
		return order(2*index+1,n-a[2*index].len);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,t[8002],res[8002];
	while(scanf("%d",&n)!=EOF)
	{
		createTree(1,n,1);
		for(int i=1;i<n;++i)
			scanf("%d",&t[i]);
		for(int i=n-1;i>0;--i)
			res[i]=order(1,t[i]+1);
		res[0]=order(1,1);
		for(int i=0;i<n;++i)
			printf("%d\n",res[i]);
	}
	return 0;
}