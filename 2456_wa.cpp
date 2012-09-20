#include <iostream>
#include <algorithm>
using namespace std;
int l,r,mid,n,c,res;
int a[100002];
bool flag;

bool check(int mid)
{
	if(c==0)
	{
		flag=true;
		return false;
	}
	c--;
	if((a[mid]-a[l])>(a[r]-a[mid]))
	{
		return false;
	}
	else
		return true;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		flag=false;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		l=0;
		r=n-1;
		c-=2;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(check(mid))
			{
				res=a[mid]-a[l];
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
			if(flag)
				break;
		}
		printf("%d\n",res);
	}
	return 0;
} 